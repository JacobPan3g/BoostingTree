#include <cstdlib>	// include atof
#include <cstdio>

#include <iostream>
#include <sstream>
using namespace std;

#include <typeinfo>

void useAtof()
{	
	char a[] = "-100.23";
	char b[] = "123";
	double c;
	c = atof(a) + atof(b);
	printf("c=%.2f\n", c);

	// other
	// "const_cast<...>" can be used to transform the type
	// (ps: on this stiation cannot use it)
	string e = "1234.2";
	double de = atof(const_cast<const char*>(e.c_str()));
	cout << de << endl;
}

// C++ style
void useStringstream()
{
	string str = "1234.567";
	double d;

	//see the type
	cout << typeid(str).name() << endl;	
	
	stringstream sstr(str);
	sstr >> d;
	cout << d << endl;
}

int main()
{
	useAtof();
	useStringstream();
	return 0;
}
