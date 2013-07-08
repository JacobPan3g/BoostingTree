/*************************************************************************
	> File Name: test.cpp
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: Mon 08 Jul 2013 09:15:50 AM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include "csv.cpp"
using namespace std;

int main()
{
	vector< vector<double> > res;
	res = csvread("input.txt");
	cout << res.size() << endl << res[0].size() << endl;
	return 0;
}
