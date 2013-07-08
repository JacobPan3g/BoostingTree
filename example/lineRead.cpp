/*************************************************************************
	> File Name: csv.cpp
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: Mon 08 Jul 2013 09:14:40 AM CST
 ************************************************************************/

#include<iostream>
#include<string>
#include<fstream>
using namespace std;

void csvread( string filename )
{
	string s;
	ifstream fobj( filename.c_str() );
	while ( getline( fobj, s ) )
		cout << s << endl;
}

/*
int main()
{
	csvread( "input.txt" );
	return 0;
}*/
