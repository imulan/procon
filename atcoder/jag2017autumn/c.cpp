#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()

bool is_prime[100005];
int prime_count[1000006];
int v[1000006];

int main()
{
    long l,r;
    cin>>l>>r;
    r++;

    fill(is_prime, is_prime+100005, true);
    fill(prime_count, prime_count+1000006, 0);
    is_prime[0] = is_prime[1] = false;
    rep(i,r-l) v[i] = l+i;

    for(long i=2; i*i<r; i++) if(is_prime[i]) {
        for(long j=2*i; j*j<r; j+=i) is_prime[j] = false;

        for (long k = i; k<r; k*=i){
            for(long j = (l+k-1)/k; j*k<r; j++){
                prime_count[j*k - l] += 1;
                v[j*k-l] /= i;
            }
        }
    }

    int ans = 0;
    rep(i,r-l) if(v[i]>1){
        if((long)v[i]*v[i] < r){
            if(is_prime[v[i]]) prime_count[i]++;
        }
        else {
            prime_count[i]++;
        }
    }
    rep(i,r-l) if(is_prime[prime_count[i]]) ans++;

    cout << ans << endl;

    return 0;
}
