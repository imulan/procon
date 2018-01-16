#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

const ll INF = LLONG_MAX;

ll solve(){
    int n;
    cin >>n;
    vector<vector<ll>> a(n,vector<ll>(n));
    rep(i,n)rep(j,n) cin >>a[i][j];

    vector<vector<ll>> d(a);
    rep(k,n)rep(i,n)rep(j,n) d[i][j] = min(d[i][j], d[i][k]+d[k][j]);

    rep(i,n)rep(j,n)if(d[i][j] != a[i][j]) return -1;

    ll ans = 0;
    rep(i,n)rep(j,i){
        bool ok = false;
        rep(k,n)if(k!=i && k!=j) ok |= (d[i][j] == d[i][k]+d[k][j]);
        if(!ok) ans += d[i][j];
    }

    return ans;
}

int main(){
    cout << solve() << endl;
    return 0;
}
