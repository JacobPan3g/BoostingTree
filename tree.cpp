/*************************************************************************
	> File Name: tree.cpp
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: Sun 07 Jul 2013 10:57:34 AM CST
 ************************************************************************/

#include <queue>
#include <cmath>
#include "GINI.cpp"
using namespace std;

#define MAX_HIGH 9

class Node			// be a class cause it have to free some spaces
{
public:
	int fIdx;
	Node *left;
	Node *right;
	int high;
	vector<int> cases;	// which cases(rows) will be considered.
	int cnum;			// the num of cases
	
	Node( const vector<int> &cases, int cnum, int high, int fIdx=-1, Node *l=NULL, Node *r=NULL ) 
	{
		this->fIdx = fIdx;
		this->left = l;
		this->right = r;
		this->high = high;
		this->cases = cases;
		this->cnum = cnum;
	}

};

class BinaryTree
{
public:
	BinaryTree( const CsvData &D );
	void disp();

	Node *root;
	vector<int> features;	// tag which feature can be considered
	vector<Node*> leaf;
	vector<int> labels;

private:
	void bulidTree( const CsvData &D );	
	void estimateLabel( const vector<double> &L, Node *node );
};

BinaryTree::BinaryTree( const CsvData &D )
{
	this->features = vector<int>(D.n, 1);
	this->bulidTree( D );
}

void BinaryTree::bulidTree( const CsvData &D )
{
	queue<Node*> q;

	vector<int> rows( D.m, 1 );
	this->root = new Node( rows, D.m, 0 );
	q.push( this->root );

	while ( !q.empty() )
	{
		Node *node = q.front();
		q.pop();

		// end 1
		if ( node->high >= MAX_HIGH )
		{
			this->leaf.push_back( node );	// a leaf needn't find minF
			this->estimateLabel( D.L, node );
			continue;
		}
		// end 2
		/// is all features used
		if ( isAll( this->features, 0 ) )
		{
			this->leaf.push_back( node );
			this->estimateLabel( D.L, node );
			continue;
		}
		// end 3
		/// already the same class
		if ( isAllSame( D.L, node->cases ) )
		{
			node->fIdx = -1;
			this->leaf.push_back( node );
			this->estimateLabel( D.L, node );
			continue;
		}
		

		// get the optimal feature
		vector<double> ginis = GINI( D, node->cases, node->cnum, this->features );
		vector<double> tmp = min( ginis, this->features );
		double minGINI = tmp[0];
		int minF = (int)tmp[1];		// gini start at first feature
		/// tag and asign
		this->features[minF] = 0;
		node->fIdx = minF;

		// separate the data by minF( need to know the minF )
		vector<int> rows1( D.m, 0 );
		vector<int> rows2( D.m, 0 );
		int tmpN1 = 0;
		int tmpN2 = 0;
		
		for ( int i = 0; i < D.m; i++ )
		{
			if ( !node->cases[i] )
				continue;

			if ( D.A[i][node->fIdx] == 1 )
			{
				tmpN1++;
				rows1[i] = 1;
			}
			else
			{
				tmpN2++;
				rows2[i] = 1;
			}

		}

		/*
		if ( tmpN1 == 0 )
			cout << "tmpN1==0" << endl;
		if ( tmpN2 == 0 )
			cout << "tmpN2==0" << endl;
		*/

		int high = node->high + 1;
		node->left = new Node( rows1, tmpN1, high );
		node->right = new Node( rows2, tmpN2, high );
		q.push(node->left);
		q.push(node->right);

	}
	
}

void BinaryTree::disp()
{
	queue<Node*> q;
	q.push(this->root);
	int num = 0;

	while( !q.empty() )
	{
		Node *node = q.front();
		q.pop();

		cout << node->fIdx;
		num++;
		if ( num < pow(2,node->high) )
		{
			cout << " ";
		}
		else
		{
			cout << endl;
			num = 0;
		}

		if ( node->left )
			q.push( node->left );
		if ( node->right )
			q.push( node->right );
	}

	cout << endl;
}

void BinaryTree::estimateLabel( const vector<double> &L, Node *node )
{
	// get the mean
	int sum = 0;
	for ( int i = 0; i < L.size(); i++ )
	{
		if ( node->cases[i] )
		{
			//cout << D.data[i][0] << " ";
			sum += L[i];
		}
	}
	//cout << endl;
	double mean = (double)sum/node->cnum;
	// estimate the label
	if ( mean >= 0 )
		this->labels.push_back(1);
	else
		this->labels.push_back(-1);
}

#include <ctime>
int main()
{
	time_t tic, toc;
	tic = clock();

	CsvData D = CsvData("a1a.csv");
	BinaryTree tree(D);
	//cout << tree.leaf.size() << endl;
	tree.disp();
	cout << "cnum\thigh\tlabel\t" << endl;
	for ( int i = 0; i < tree.leaf.size(); i++ )
		cout << tree.leaf[i]->cnum << "\t" 
			 << tree.leaf[i]->high << "\t" 
			 << tree.labels[i] << endl;
	cout << tree.leaf.size() << endl;

	toc = clock();
	double tol = (double)(toc-tic)/CLOCKS_PER_SEC;
	cout << "Time: " << tol << " s" << endl;

	return 0;
}
