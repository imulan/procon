#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const int N = 100010;
vector<int> G[N];

int main(){
    int n,m;
    scanf(" %d %d", &n, &m);

    rep(i,m){
        int a,b;
        scanf(" %d %d", &a, &b);
        --a;
        --b;
        G[a].pb(b);
        G[b].pb(a);
    }

    vector<int> x(n,-1);
    vector<int> e(n);
    rep(i,n){
        int ct = 0;
        for(int j:G[i])if(x[j]>=0) ct += (!x[j]);

        int xx = 0;
        if(ct>=2) xx = 1;

        int now = i;
        while(1){
            x[now] = xx;
            int nx = -1;
            for(int j:G[now])if(x[j] == xx){
                ++e[now];
                ++e[j];
                if(e[j]==2){
                    nx = j;
                    for(int k:G[nx]){
                        if(x[k] == xx){
                            --e[nx];
                            --e[k];
                        }
                    }
                }
            }
            if(nx == -1) break;
            now = nx;
            xx = !xx;
        }
    }

    vector<int> ans[2];
    rep(i,n) ans[x[i]].pb(i);

    if(ans[1].size()==0){
        printf("1\n");
        rep(i,n) printf("%d%c", i+1, " \n"[i==n-1]);
        return 0;
    }

    printf("2\n");
    rep(i,2){
        int sz = ans[i].size();
        rep(j,sz) printf("%d%c", ans[i][j]+1, " \n"[j==sz-1]);
    }
    return 0;
}
