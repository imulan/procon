#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

#define X first
#define Y second

using P = pair<ll,ll>;
using VP = vector<P>;

ll cross(P a, P b){
    return a.X*b.Y - a.Y*b.X;
}

ll area(const VP &ps){
    ll a = 0;
    rep(i,ps.size()) a += cross(ps[i], ps[(i+1)%ps.size()]);
    return a;
}

// S = i + b/2 - 1
// S:多角形の面積 i:内部にある格子点の数 b:辺上の格子点の数

int main(){
    int n;
    scanf(" %d", &n);

    VP p(n);
    rep(i,n) scanf(" %lld %lld", &p[i].X, &p[i].Y);

    ll SS = abs(area(p));

    ll b = 0;
    rep(i,n){
        P A = p[i], B = p[(i+1)%n];
        
        ll dx = abs(A.X-B.X), dy = abs(A.Y-B.Y);
        ll G = __gcd(dx,dy);
        b += G+1;
    }
    b -= n;

    printf("%lld\n", (SS-b+2)/2);
    return 0;
}