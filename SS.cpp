/*************************************************************************
	> File Name: SQ.cpp
	> Author: Jacob Pan
	> Mail: zhenjian3g@gmail.com 
	> Created Time: Mon 08 Jul 2013 01:36:58 PM CST
 ************************************************************************/

#include "CsvData.cpp"
#include <cmath>
using namespace std;

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
}

vector<double> measure( const CsvData &D, const vector<int> &r, int m, const vector<int> &c )
{
	vector<double> ss;
	for ( int i = 0; i < D.n; i++ )	
	{
		if ( !c[i] )
			continue;
			
		for ( int k = 0; k <= 4; k++ )
		{
			// get the average
			int dNum = 0;
			double cAve1 = 0;
			double cAve2 = 0;
			for ( int j = 0; j < D.m; j++ )
			{
				if ( !r[j] )
					continue;

				if ( discretize( D.A[j][i] ) == k )
				{
					dNum++;
					cAve1 += D.L[j];
				}
				else
				{
					cAve2 += D.L[j];
				}
			}
			cAve1 /= dNum;
			cAve2 /= (D.m-dNum);
	
			// get the ss
			double s1 = 0;
			double s2 = 0;
			for ( int j = 0; j < D.m; j++ )
			{
				if ( !r[j] )
					continue;
				
				if ( discretize( D.A[j][i] ) == k )
					s1 += pow( D.L[j]-cAve1, 2 );
				else
					s2 += pow( D.L[j]-cAve2, 2 );
			}
			double s = (double)dNum/D.m * s1 + (double)(D.m-dNum)/D.m * s2;
			ss.push_back(s);
		}
	}
	return ss;
}


double estimateLabel( const vector<double> &L, vector<int> tag )
{
	// get the mean
	int sum = 0;
	int num = 0;
	for ( int i = 0; i < L.size(); i++ )
	{
		if ( tag[i] )
		{
			sum += L[i];
			num++;
		}
	}

	// estimate the label
	double mean = (double)sum/num;
	return mean;
}



/*
#include <cstdio>
int main()
{
	CsvData D = CsvData("data.csv");
	
	vector<int> r(D.m, 1), c(D.n, 1);
	vector<double> res = measure( D, r, D.m, c );
	cout << res.size() << endl;

	for ( int i = 0; i < res.size(); i++ )
		printf("%.10lf\n",res[i]);
	
	return 0;
}*/
