#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const int INF = 191919;

using pi = pair<int,int>;

int main(){
    int n,r,h,m;
    cin >>n >>r >>h >>m;
    --r;
    --h;
    --m;

    vector<vector<int>> G(n);
    rep(i,n-1){
        int a,b;
        cin >>a >>b;
        --a;
        --b;
        G[a].pb(b);
        G[b].pb(a);
    }

    int ans = INF;
    rep(x,n){

        vector<int> d(n,INF);
        d[x] = 0;
        queue<int> que;
        que.push(x);
        while(!que.empty()){
            int v = que.front();
            que.pop();
            for(int e:G[v]){
                if(d[e] > d[v]+1){
                    d[e] = d[v]+1;
                    que.push(e);
                }
            }
        }

        int md = 0;
        rep(i,n) md = max(md,d[i]);

        int ad = 1;
        if(x==h || x==m) ad = 0;
        ans = min(ans, md+ad);
    }

    cout << ans << endl;
    return 0;
}