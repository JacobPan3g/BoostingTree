/*************************************************************************
	> File Name: GINI.cpp
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: Mon 08 Jul 2013 01:36:58 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include "CsvData.h"
using namespace std;

vector<double> GINI( const CsvData &D, const vector<int> &r, int m, const vector<int> &c )
{
	vector<double> ginis(D.n-1);
	for ( int i = 1; i < D.n; i++ )		// the feature from 1 to n
	{
		if ( !c[i] )
			continue;

		int dNum = 0;
		int cNum1 = 0;
		int cNum2 = 0;
		for ( int j = 0; j < D.m; j++ )
		{
			if ( !r[i] )
				continue;

			if ( D.data[j][i] == 1 )
			{
				dNum++;
				if ( D.data[j][0] == 1 )
					cNum1++;
			}
			else
			{
				if ( D.data[j][0] == 1 )
					cNum2++;
			}
		}
		double P = dNum/(m+1e-8);
		double p1 = cNum1/(dNum+1e-8);
		double p2 = cNum2/(m-dNum+1e-8);
		ginis[i-1] = P*(2*p1*(1-p1)) + (1-P)*(2*p2*(1-p2));
	}
	return ginis;
}




/*
int discretize( double d )
{
	int res = 0;	// 0 <= d <= 0.2
	if ( 0.2 < d && d <= 0.4 )
		res = 1;
	else if ( 0.4 < d && d <= 0.6 )
		res = 2;
	else if ( 0.6 < d && d <= 0.8 )
		res = 3;
	else			// 0.8 < d <= 1
		res = 4;

	return res;
}*/

/*
int main()
{
	CsvData D = CsvData("a1a.csv");
	
	vector<int> r(D.m, 1), c(D.n, 1);
	vector<double> res = GINI( D, r, D.m, c );
	cout << res.size() << endl;

	for ( int i = 0; i < res.size(); i++ )
		cout << res[i] << endl;
	
	return 0;
}*/
