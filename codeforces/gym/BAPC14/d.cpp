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

void solve(){
    int n,g;
    scanf(" %d %d", &n, &g);
    --g;

    vector<vector<int>> nx(n, vector<int>(4));
    rep(i,n)rep(j,4){
        scanf(" %d", &nx[i][j]);
        --nx[i][j];
    }

    int ct = 0;
    vector<vector<int>> cc(n,vector<int>(2,-1));
    rep(i,n)rep(j,2)if(cc[i][j] == -1){
        cc[i][j] = ct;
        queue<pi> que;
        que.push({i,j});
        while(!que.empty()){
            pi now = que.front();
            que.pop();
            int v = now.fi, d = now.se;

            rep(k,2){
                int idx = nx[v][2*k+d];
                int nd = -1;
                rep(l,4){
                    if(nx[idx][l] == v) nd = l%2;
                }
                assert(nd>=0);

                if(cc[idx][nd] == -1){
                    cc[idx][nd] = ct;
                    que.push({idx,nd});
                }
            }
        }

        ++ct;
    }

    int ans = ct - 1 - (cc[g][0]!=cc[g][1]);
    printf("%d\n",ans);
}

int main(){
    int T;
    scanf(" %d", &T);
    while(T--) solve();
    return 0;
}
