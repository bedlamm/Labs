#include<stdio.h>
#include <stdlib.h>
#include <math.h>
#include<locale.h>
const int N=3;
void read_matr (int a[][N],size_t N)
{
	int i,j;
	for (i=0;i<N;i++)
	{
		for (j=0;j<N;j++)
		{
		scanf("%d",&a[i][j]);
		}
	}
}
int main ()
{
	setlocale(LC_ALL, "RUS");
	int a[N][N];
	int i,j,k,l;
	printf("¬ведите элементы матрицы а размера %d*%d \n",N,N);
	read_matr(a,N);
    for(i=0;i<N;i++)
    {
    	for(j=0;j<N;j++)
    	{
    		k=a[i][j];
    		l=a[i][N-j+1];
    		if (k!=l)
    		{
    			printf("%d ",l);
			}
		}
	}
    return 0;
}
