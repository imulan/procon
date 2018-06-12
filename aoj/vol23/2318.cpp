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

const int N = 300;

int n,e,t;
int w[N];
vector<vector<int>> rule[N];

const int INF = 19191919;
int dp[N];

int main(){
    cin >>n >>e >>t;
    --t;

    rep(i,n) cin >>w[i];

    rep(i,e){
        int g,c;
        cin >>g >>c;
        --g;

        vector<int> s(c);
        rep(j,c){
            cin >>s[j];
            --s[j];
        }
        rule[g].pb(s);
    }

    fill(dp,dp+N,INF);
    rep(i,n)if(w[i]==1) dp[i]=1;

    rep(loop,n){
        rep(i,n){
            for(vector<int> r:rule[i]){
                int sz = r.size();

                vector<int> v;
                for(int nx:r) v.pb(dp[nx]);
                sort(all(v));

                bool ok = true;
                rep(j,sz)if(v[j]==INF) ok=false;
                if(ok){
                    int tmp = 0;
                    rep(j,sz) tmp = max(tmp, v[j]+(sz-1-j));
                    dp[i] = min(dp[i], tmp);
                }
            }
        }
    }

    int ans = dp[t];
    if(ans == INF) ans = -1;
    cout << ans << endl;
    return 0;
}
