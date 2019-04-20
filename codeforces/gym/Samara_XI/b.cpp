#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define X first
#define Y second

using P = pair<ll,ll>;

int main(){
    int n;
    cin >>n;
    vector<P> p(n);
    rep(i,n) cin >>p[i].X >>p[i].Y;

    ll ans = LLONG_MAX;
    rep(i,n){
        ll tmp = 0;
        rep(j,3){
            P a = p[(i+j)%n], b = p[(i+(j+1)%3)%n];
            tmp += a.X*b.Y - a.Y*b.X;
        }
        ans = min(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}