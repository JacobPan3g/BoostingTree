/*************************************************************************
	> File Name: JPTool.cpp
	> Author: Jacob Pan
	> Mail: zhenjian3g@gmail.com 
	> Created Time: Tue 09 Jul 2013 04:31:42 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;

template <class T>
vector<T> min( const vector<T> &ginis, vector<int> tag=vector<int>() )
{	
	if ( tag.size() == 0 )
		tag = vector<int>( ginis.size(), 1 );

	vector<T> res(2, 0);	// idx 1 for min, idx 2 for idx
	res[0] = 1e8;

	for ( int i = 0; i < ginis.size(); i++ )
		if ( tag[i] == 1 && ginis[i] < res[0] )
		{
			res[0] = ginis[i];
			res[1] = i;
		}
	return res;
}

template <class T>
vector<T> split( string str, string pattern )
{
	vector<T> res;
	str += pattern;
	int i = 0;
	int pos = str.find( pattern, i );
	
	while( pos != -1 )
	{
		string s = str.substr( i, pos-i );
		T d = atof( s.c_str() );
		res.push_back( d );
		i = pos + pattern.size();
		pos = str.find( pattern, i );
	}
	return res;
}

/*
int main()
{
	// min()
	vector<double> a;
	a.push_back( 0.1 );
	a.push_back( 0.2 );
	a.push_back( 0.01 );
	a.push_back( 0.3 );
	a.push_back( 0.4 );
	vector<double> b = min(a);
	cout << b[0] << endl << b[1] << endl;

	// spilt()
	string s = "123,456,78.94";
	vector<double> res = split<double>(s, ",");
	for ( int i = 0; i < res.size(); i++ )
		cout << res[i] << endl;

	return 0;
}
*/

