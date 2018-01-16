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

const int INF = 191919;

const int N = 1001;
vector<int> ch[N];
int dp[N][2];

const int X = 5005;
int cost[X], nx[X];

int main(){
    int n;
    cin >>n;
    vector<int> p(n);
    for(int i=1; i<n; ++i){
        cin >>p[i];
        --p[i];
        ch[p[i]].pb(i);
    }
    vector<int> x(n);
    rep(i,n) cin >>x[i];

    fill(dp[0],dp[N],INF);
    for(int i=n-1; i>=0; --i){
        if(ch[i].size()==0){
            rep(j,2) dp[i][j] = 0;
            continue;
        }

        // 頂点iをjで塗る
        rep(j,2){
            vector<int> fr;
            int same=0, other=0;
            // 子の塗り方
            for(int idx:ch[i]){
                if(dp[idx][j]==INF){
                    // idxを違う色で塗らないといけない
                    same += dp[idx][!j];
                    other += x[idx];
                }
                else if(dp[idx][!j]==INF){
                    // idxを同じ色で塗らないといけない
                    other += dp[idx][j];
                    same += x[idx];
                }
                else{
                    // どっちで塗っても良い
                    fr.pb(idx);
                }
            }
            if(same>x[i] || other>=INF) continue;

            // どっちで塗っても良い頂点たちの塗り方を考える
            fill(cost,cost+X,INF);
            cost[same]=other;
            for(int v:fr){
                fill(nx,nx+X,INF);
                for(int k=X-1; k>=0; --k)if(cost[k]<INF){
                    // vをiと同じ色で塗る
                    if(k+x[v]<X) nx[k+x[v]] = min(nx[k+x[v]], cost[k]+dp[v][j]);
                    // vをiと異なる色で塗る
                    if(k+dp[v][!j]<X) nx[k+dp[v][!j]] = min(nx[k+dp[v][!j]], cost[k]+x[v]);
                }
                rep(k,X) cost[k] = nx[k];
            }
            rep(k,x[i]+1) dp[i][j] = min(dp[i][j],cost[k]);

            // rep(k,x[i]+1)if(cost[k]<INF) printf("  cost[%d] = %d\n",k,cost[k]);
            // printf(" dp[%d][%d] = %d\n",i,j,dp[i][j]);
        }
    }

    string ans = "IMPOSSIBLE";
    rep(i,2)if(dp[0][i]<INF) ans = "POSSIBLE";
    cout << ans << endl;
    return 0;
}
