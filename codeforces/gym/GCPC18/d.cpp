#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const ll INF = LLONG_MAX/3;

int main(){
    int n;
    scanf(" %d", &n);
    vector<int> a(n);
    rep(i,n) scanf(" %d", &a[i]);

    vector<ll> z(n+1);
    rep(i,n){
        z[i+1] = -z[i]+a[i];
    }

    ll l=0, r=INF;
    rep(i,n+1){
        if(i%2==0) l = max(l, -z[i]);
        else r = min(r,z[i]);
    }

    cout << max(r-l+1, 0LL) << "\n";
    return 0;
}

