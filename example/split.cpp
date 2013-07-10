#include <cstdio>
#include <cstring>	// include strtok

#include <string>
#include <vector>
#include <iostream>
using namespace std;

/*
 * Cause it dose't know what is in the strtok() (aka, free or not)
 * the string to be sqlited cannot be const 
 * (ps: string.c_str() is const ), so, sqlit a string class is not suit
 * String class should use the next method. X
 * (Unn... It found that this method is also use in String class. Just Delete when you New.)
 */
void useStrtok()
{
	char s[] = "hello,world,111,222";
	const char *spliter = ",";
	char *p;
	p = strtok(s,spliter);
	while(p)
	{
		printf( "%s\n", p );
		p = strtok( NULL, spliter );
	}	
}

// my implement considered better than Internet
vector<string> split( string str, string pattern )
{
	vector<string> res;
	str += pattern;
	int i = 0;
	int pos = str.find( pattern, i );
	
	while( pos != -1 )
	{
		string s = str.substr( i, pos-i );
		res.push_back( s );
		i = pos + pattern.size();
		pos = str.find( pattern, i );
	}
	return res;
}

/* 
 * useStl()
 **find(string pattern, size_t pos = 0) const
 *	if find, return pos, otherwise, return npos
 *	(ps: npos is -1 in int, a huge number in unsigned)
 **substr(size_t pos = 0, size_t len = npos) const
 *	get a substring begin at pos, and its length is len
 */
void useStl()
{
	string s = "111,2222,333.4";
	vector<string> res = split( s, "," );
	for ( int i = 0; i < res.size(); i++ )
		cout << res[i] << endl;
}

int main()
{
	useStrtok();
	useStl();	
	return 0;
}
