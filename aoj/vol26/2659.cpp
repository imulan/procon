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

ll lcm(ll x, ll y){
    return x/__gcd(x,y)*y;
}

int main(){
    int n,m,d;
    cin >>n >>m >>d;

    vector<int> a(m);
    rep(i,m) cin >>a[i];

    vector<vector<int>> r(d, vector<int>(m));
    rep(i,d)rep(j,m) cin >>r[i][j];

    ll now = n;
    rep(i,d){
        ll nx = now;
        ll L = 1;
        rep(j,m){
            if(r[i][j] == -1) continue;

            vector<bool> vis(a[j]);
            while(nx>=0 && !vis[nx%a[j]] && nx%a[j]!=r[i][j]){
                vis[nx%a[j]] = true;
                nx -= L;
            }

            if(nx<0 || nx%a[j]!=r[i][j]){
                cout << -1 << endl;
                return 0;
            }

            L = lcm(L, a[j]);
        }
        now = nx;
    }
    cout << now << endl;
    return 0;
}
