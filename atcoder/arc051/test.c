#include <stdio.h>

int counter = 0;
int gcd(int a, int b) {
    if (b == 0) return a;
    counter++;
    return gcd(b, a%b);
}

int main() {

	int c[41]={0};
	for(int i=1; i<100000; ++i)
	{
		for(int j=1; j<=100000; ++j)
		{
			counter=0;
			gcd(i, j);
			if(c[counter]==0)
			{
				c[counter]=1;
				printf("%d : %d %d\n",counter,i,j);
			}
		}
	}

    printf("%d\n", counter);
}
