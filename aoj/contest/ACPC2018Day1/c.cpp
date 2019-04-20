#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))

const int N = 10000100;

bool prime[N];

int main(){
    fill(prime,prime+N,true);
    prime[0]=prime[1]=false;
    for(int i=2; i<N; ++i){
        if(prime[i])for(int j=2*i; j<N; j+=i) prime[j]=false;
    }

    int n;
    cin >>n;

    int ans = 0;
    for(int i=3;i<=n;++i)if(prime[i]){
        if(prime[2+i]) ans += 2;
    }
    cout << ans << endl;
    return 0;
}
