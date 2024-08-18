#include<iostream>
#include<math.h>
#include<fstream>
using namespace std;
int main() 
{
	int i, iter = 0;
	const int n = 51;
	double array1[n], array2[n];
	double dx = 0.1, dt = 0.03, u = 1.0;
	ofstream fout("file.txt");
	for (i = 0;i<n;i++) 
	{
		array1[i] = 0.0;
		array2[i] = 0.0;
		if (i <= 20 && i >= 10) 
			array1[i] = cos(0.314159265*i);
	}
	for (iter = 0; iter < 600; iter++) 
	{
		for (i = 0; i < n; i++) 
				array2[i] = 0.5*(array1[i-1]+array1[i+1])-u*dt/(2.0*dx)*(array1[i+1]-array1[i-1]);
		for (i = 0; i < n; i++) 
				array1[i] = array2[i];
		if(iter%450 == 0)
		{
				for (i = 0;i<n;i++) 
				{
					fout << array2[i] << '\t';
				}
			fout<<endl;
		}
	}
	return 0;
}
