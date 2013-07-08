#include <cstdio>
#include <cstring>	// include strtok

int main()
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
	return 0;
}
