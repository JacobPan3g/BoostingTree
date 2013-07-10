#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	clock_t tic, toc;
	double totaltime;
	tic = clock();

	for ( int i = 0; i < 1e9; i++ )

	toc = clock();
	totaltime = (double)(toc-tic)/CLOCKS_PER_SEC;
	cout << "\nI take " << totaltime << " s." << endl;

	return 0;
}
