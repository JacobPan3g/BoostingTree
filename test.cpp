/*************************************************************************
	> File Name: test.cpp
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: Mon 08 Jul 2013 09:15:50 AM CST
 ************************************************************************/

#include "GINI.cpp"
using namespace std;

int main()
{
	CsvData D = CsvData("a1a.csv");
	cout << D.m << " " << D.n << endl;
	
	vector<int> r(D.m, 1), c(D.n, 1);
	vector<double> gini = GINI( D, r, D.m, c );

	for ( int i = 0; i < gini.size(); i++ )
		cout << gini[i] << endl;

	
	return 0;
}

