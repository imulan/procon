#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

using vi = vector<int>;
using mat = vector<vi>;

using pi = pair<int,int>;

int main(){
    int h,w;
    cin >>h >>w;

    mat a(h,vi(w)), b(h,vi(w));
    rep(i,h)rep(j,w) cin >>a[i][j];

    vector<pi> ans;
    rep(i,h-1)rep(j,w-1){
        bool ok = true;
        rep(ii,2)rep(jj,2) ok &= a[i+ii][j+jj];
        if(ok){
            rep(ii,2)rep(jj,2) b[i+ii][j+jj] = 1;
            ans.pb({i+1,j+1});
        }
    }

    if(a != b) cout << -1 << "\n";
    else{
        cout << ans.size() << "\n";
        for(pi p:ans) cout << p.fi << " " << p.se << "\n";
    }
    return 0;
}
