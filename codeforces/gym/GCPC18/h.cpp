#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

ll POW(ll x, ll n){
//    printf(" %lld %lld  = ",x,n);
    ll ret = 1;
    while(n){
        if(n&1) ret *= x;
        x *= x;
        n >>= 1;
    }
//    printf(" %lld\n",ret);
    return ret;
}

void solve(){
    ll m;
    cin >>m;

    for(int n=3; n<55; ++n){
        ll t = 0;
        int s = 1;
        while(t<m){
            t += POW(s,n-1);
            if(t == m){
                printf("%d %d\n",n,s);
                return;
            }
            ++s;
        }
    }
    printf("impossible\n");
}

int main(){
    solve();
    return 0;
}

