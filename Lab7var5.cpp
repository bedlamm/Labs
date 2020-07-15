#include<stdio.h>
#include <stdlib.h>
#include<locale.h>
size_t M=20;
void read_arr(int a[], size_t M)
{
	int i;
	for (i=0;i<M;i++)
	{
		scanf("%d", &a[i]);
	}
}
int main ()
{
	setlocale(LC_ALL, "RUS");
	int a[M];
	int i,j;
	printf("¬ведите %d элементов массива \n",M);
	read_arr(a,M);
    for (i=0;i<M;i++)
    {
            for (j=0;j<M;j++)
            {
                if (a[i]%a[j]==0 && i!=j) 
                {
                	printf (" %2d",a[i]);
                	break;                      
				}
            } 
    }      
    return 0;
}
