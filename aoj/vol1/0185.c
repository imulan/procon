#include <stdio.h>
 
int main(void)
{
    static char prime[1000002];
    long i, j;
    long n, ans;
     
    for (i = 1; i <= 1000000; i += 2){
        prime[i] = 1;
    }
     
    prime[1] = 0;
    prime[2] = 1;
     
    for (i = 1; i <= 1000; i += 2){
        if (prime[i] == 1){
            for (j = 3; i * j <= 1000000; j += 2){
                prime[i * j] = 0;
            }
        }
    }
     
    while (1){
        scanf(" %ld", &n);
         
        if (n == 0){
            break;
        }
         
        ans = 0;
        for (i = 2; i <= n / 2; i++){
            if (prime[i] && prime[n - i]){
                ans++;
            }
        }
         
        printf("%ld\n", ans);
    }
    return 0;
}