/*************************************************************************
	> File Name: csv.cpp
	> Author: Jacob Pan
	> Mail: zhenjian3g@gmail.com 
	> Created Time: Mon 08 Jul 2013 09:14:40 AM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <vector>
using namespace std;



/*
 * csvread()
 * mainly in 3 parts
 * 1. read by lind
 * 2. split by ','
 * 3. transform char[] to num
 */
vector< vector<double> > csvread( string filename )
{
	string line;
	ifstream fobj( filename.c_str() );
	const char *spliter = ",";
	char *p;

	vector< vector<double> > res;	// the blank '> >' is necessary

	while ( getline( fobj, line ) )		//* the main cmd to read line
	{
		vector<double> tmp;
		//* split each line
		char * s = strdup( line.c_str() );
		p = strtok( s, spliter );
		while( p )
		{
			//* transform char[] to num
			double d = atof( p );
			tmp.push_back( d );
			p = strtok( NULL, spliter );
		}
		delete[] s;
		res.push_back( tmp );
	}

	/*
	// just print for test
	cout << "size:" << res.size() << endl;
	for ( int i = 0; i < res.size(); i++ )
		for ( int j = 0; j < res[i].size(); j++ )
			cout << res[i][j] << endl;
	*/

	return res;
}

//void disp

/*
int main()
{
	csvread( "input.txt" );
	return 0;
}*/
