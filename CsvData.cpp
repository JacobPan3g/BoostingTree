/*************************************************************************
	> File Name: csv.cpp
	> Author: Jacob Pan
	> Mail: zhenjian3g@gmail.com 
	> Created Time: Mon 08 Jul 2013 09:14:40 AM CST
 ************************************************************************/

#include <fstream>
#include "JPTool.cpp"
using namespace std;

class CsvData
{
public:
	CsvData( string filename );
	void disp();

	int m;
	int n;
	vector<double> L;
	vector< vector<double> > A;

private:
	void csvread( string filename );
};

CsvData::CsvData( string filename )
{
	this->csvread( filename );
	m = A.size();
	n = A[0].size();
}


/*
 * csvread()
 * mainly in 3 parts
 * 1. read by lind
 * 2. split by ','
 * 3. transform char[] to num
 */
void CsvData::csvread( string filename )
{
	string line;
	ifstream fobj( filename.c_str() );

	//vector< vector<double> > res;	// the blank '> >' is necessary

	while ( getline( fobj, line ) )		//* the main cmd to read line
	{
		vector<double> tmp = split<double>( line, "," );
		this->L.push_back( tmp[0] );
		tmp.erase( tmp.begin() );
		this->A.push_back( tmp );
	}
	
	/*
	// just print for test
	cout << "size:" << res.size() << endl;
	for ( int i = 0; i < res.size(); i++ )
		for ( int j = 0; j < res[i].size(); j++ )
			cout << res[i][j] << endl;
	*/
}

void CsvData::disp()
{
	for ( int i = 0; i < this->m; i++ )
	{
		cout << this->L[i] << " ";
		for ( int j = 0; j < this->n; j++ )
			cout << this->A[i][j] << " ";
		cout << endl;
	}
}



/*
int main()
{
	CsvData D( "a1a.csv" );
	cout << D.m << " " << D.n << endl;
	D.disp();
	return 0;
}
*/
