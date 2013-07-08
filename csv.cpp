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

class CsvData
{
public:
	CsvData( string filename );
	vector< vector<double> > csvread( string filename );
	void disp();

	int size[2];
	vector< vector<double> > data; 
};

CsvData::CsvData( string filename )
{
	this->data = this->csvread( filename );
	size[0] = data.size();
	size[1] = data[0].size();
}


/*
 * csvread()
 * mainly in 3 parts
 * 1. read by lind
 * 2. split by ','
 * 3. transform char[] to num
 */
vector< vector<double> > CsvData::csvread( string filename )
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

void CsvData::disp()
{
	for ( int i = 0; i < size[0]; i++ )
		for ( int j = 0; j < size[1]; j++ )
			cout << this->data[i][j] << endl;	
}



/*
int main()
{
	csvread( "input.txt" );
	return 0;
}*/
