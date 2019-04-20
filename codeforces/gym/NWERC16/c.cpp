#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

using D = long double;

int main(){
    ll x,y;
    cin >>x >>y;

    int mul = 1;
    if(x<0){
        mul = -1;
        x = -x;
    }

    int n;
    cin >>n;

    ll yy = y;
    vector<ll> w(n);
    vector<D> f(n);
    rep(i,n){
        ll l,u;
        cin >>l >>u >>f[i];
        w[i] = u-l;
        yy -= w[i];
    }

    w.pb(yy);
    f.pb(1);

    D sg = 0;
    rep(i,n+1){
        sg += w[i]*f[i];
    }
    printf("%.9Lf\n", mul*x/sg);
    return 0;
}