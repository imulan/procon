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

using pi = pair<int,int>;

const int N = 202;
int dp[N][N];

int main(){
    int n,p;
    cin >>n >>p;

    vector<pi> v(n);
    rep(i,n) cin >>v[i].fi >>v[i].se;
    sort(all(v));

    vector<pi> g,b;
    rep(i,n){
        bool good = false;
        rep(j,n){
            if(v[i].fi==v[j].fi && v[i].se==v[j].se) continue;

            good |= (v[i].fi <= v[j].fi && v[j].se <= v[i].se);
        }

        if(good) g.pb(v[i]);
        else b.pb(v[i]);
    }
    int G = g.size();
    int B = b.size();

    fill(dp[0],dp[N],-1010101);
    dp[0][0] = 0;
    rep(i,B){
        rep(j,p){
            for(int k=i+1; k<=B; ++k){
                int add = b[i].se - b[k-1].fi;
                if(add>0) dp[k][j+1] = max(dp[k][j+1], dp[i][j]+add);
            }
        }
    }

    vector<int> L;
    for(const auto &pp:g) L.pb(pp.se-pp.fi);
    sort(all(L), greater<int>());

    int ans = 0;
    rep(i,p+1){
        int rem = p-i;
        if(rem>G) continue;

        int tmp = dp[B][i];
        rep(j,rem) tmp += L[j];

        ans = max(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}
