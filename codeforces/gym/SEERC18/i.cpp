#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0; (i)<(int)(n); ++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const int N = 114;
set<int> G[N];

ll dp[N];

int main(){
    int n,m;
    scanf(" %d %d", &n, &m);
    rep(i,m){
        int u,v;
        scanf(" %d %d", &u, &v);
        --u;
        --v;
        G[u].insert(v);
        G[v].insert(u);
    }    
    
    vector<bool> rem(n,true);
    
    vector<int> p;
    p.pb(0);
    rep(i,n){
        int a = G[i].size();
        for(int e:G[i]){
            G[e].erase(i);
        }
        G[i].clear();
        
        int idx = 0;
        int ct = 0;
        while(idx<n){
            if(rem[idx]) ++ct;
            if(ct == a+1) break;            
            ++idx;
        }
        p.pb(idx+1);
        rem[idx] = false;        
                
     //   printf(" %d",idx+1);
    }
    //printf("\n");
    p.pb(n+1);
    
    dp[0] = 1;
    rep(i,n+2){
        vector<bool> ap(n+5);
        for(int j=i+1; j<n+2; ++j){
            if(p[i] > p[j]) continue;
            
            bool ok = true;
            for(int k=p[i]; k<p[j]; ++k){
                if(ap[k]) ok = false;
            }
            if(ok){
                //printf("%d -> %d\n",i,j);
                dp[j] += dp[i];
            }
            
            ap[p[j]] = true;
        }
    }
    
    printf("%lld\n", dp[n+1]);
    return 0;
}
