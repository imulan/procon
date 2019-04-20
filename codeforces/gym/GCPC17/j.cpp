#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

vector<string> identify(vector<string> s){
    int n = s.size();
    vector<bool> u(n,true);

    rep(i,n){
        int I = s[i].size();
        rep(j,n)if(j!=i){
            int J = s[j].size();
            if(I > J) continue;

            rep(k,J-I+1){
                string t = s[j].substr(k,I);
                if(t == s[i]) u[i] = false;
            }
        }
    }

    vector<string> ret;
    rep(i,n)if(u[i]) ret.pb(s[i]);
    return ret;
}

using pi = pair<int,int>;
const pi INF(1919,1919);

int main(){
    int h,w,n;
    cin >>h >>w >>n;

    vector<string> s(n);
    rep(i,n) cin >>s[i];

    s = identify(s);
    n = s.size();

    vector<int> sz(n);
    rep(i,n) sz[i] = s[i].size();

    vector<vector<int>> cv(n,vector<int>(n));
    rep(i,n){
        rep(j,n)if(i!=j){
            int I = sz[i], J = sz[j];

            for(int k=1; k<=min(I,J); ++k){
                string suf = s[i].substr(I-k);
                string pre = s[j].substr(0,k);
                if(suf == pre) cv[i][j] = k;
            }

//            cout << s[i] << " -- " << s[j] << " : " << cv[i][j] << endl;
        }
    }


    vector<vector<pi>> dp(1<<n, vector<pi>(n,INF));
    vector<vector<pi>> par(1<<n, vector<pi>(n,INF));

    rep(i,n)if(sz[i]<=w){
        dp[1<<i][i] = {0,sz[i]};
    }

    rep(mask,1<<n)rep(i,n){
        if( !(mask>>i&1) ) continue;
        if(dp[mask][i] == INF) continue;

        int y = dp[mask][i].fi, x = dp[mask][i].se;

//        printf(" %d %d :: (%d, %d)\n",mask,i,y,x);

            rep(j,n)if( !(mask>>j&1) ){
            int nmask = mask|(1<<j);
            int nx = x + sz[j] - cv[i][j];
//            printf(" j %d :: nx %d\n",j,nx);

            if(nx<=w){
                pi nv(y,nx);
                if(dp[nmask][j] > nv){
                    dp[nmask][j] = nv;
                    par[nmask][j] = {mask,i};
                }
            }

            int ny = y+1;
            nx = sz[j];
            if(ny<h && nx<=w){
                pi nv(ny,nx);
                if(dp[nmask][j] > nv){
                    dp[nmask][j] = nv;
                    par[nmask][j] = {mask,i};
                }
            }
        }
    }

    int mask = (1<<n)-1;
    int now = -1;
    rep(i,n){
        if(dp[mask][i]!=INF) now = i;
    }

    if(now == -1){
        cout << "impossible" << endl;
        return 0;
    }

    vector<string> ans(h,string(w,'A'));
    while(mask){
        pi p = par[mask][now];
        int y = dp[mask][now].fi, x = dp[mask][now].se;

        rep(i,sz[now]){
            ans[y][x+i-sz[now]] = s[now][i];
        }

        mask ^= (1<<now);
        now = p.se;
    }

    rep(i,h) cout << ans[i] << endl;
    return 0;
}