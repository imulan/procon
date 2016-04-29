#include <stdio.h>
 
char prime[10000001];
 
void SetPrime(int max){
	int i, j;
    
	for(i = 4; i <= max; i += 2){
    	prime[i] = 1;
    }
    
    for(i = 3; i * i <= max; i += 2){
        if(prime[i] == 0){
            for(j = i * 2; j <= max; j += i){
                prime[j] = 1;
	        }
    	}
    }
    
}
 
int main(void){
    long n;
    SetPrime(10000000);
    
    while(scanf("%ld", &n) * n != 0){
        long i;
        if(n%2==0) n--; 
         
        for(i = n; i >= 10; i-=2){
            if(prime[i] + prime[i - 2] + prime[i - 6] + prime[i - 8] == 0){
                printf("%ld\n", i);
                break;
            }
        }
    }
     
    return 0;
}