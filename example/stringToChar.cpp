/*
 * tranform string to char[]
 * ( ps: c_str() just tranforms it to const char[] )
 */

#include <iostream>
#include <cstdio>
using namespace std;

#include <string>
#include <cstring>		// include strcpy

void useStrcpy()
{
	string str("s334");
	char *a = new char[(str.size()+1)];	// the last one to store '/0'
	strcpy(a,str.c_str());
	printf("%s\n", a);

	delete[] a;	// free for C	
}

void useStrdup()
{
	string text = "abc";
	char *a;
	a = strdup(text.c_str());
	cout << a << endl;
	delete[] a;
}

int main()
{
	useStrcpy();
	useStrdup();
	return 0;
}
