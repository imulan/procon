#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define repl(i,a,b) for(int (i)=(int)(a);(i)<(int)(b);++(i))
#define rep(i,n) repl(i,0,n)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const int INF = 19191919;

int main(){
    int T;
    scanf(" %d", &T);
    while(T--){
        int n;
        scanf(" %d", &n);
        
        vector<ll> x(n),y(n),r(n);
        rep(i,n) scanf(" %lld %lld %lld", &x[i], &y[i], &r[i]);
        
        auto touch = [&](int a, int b){
            ll dx = x[a]-x[b], dy = y[a]-y[b];
            ll d = dx*dx + dy*dy;
            
            ll R = r[a]+r[b];
            return d == R*R;
        };
        
        vector<vector<int>> G(n);
        rep(i,n)rep(j,i){
            if(touch(i,j)){
                G[i].pb(j);
                G[j].pb(i);
            }
        }
        
        vector<int> d(n,INF);
        d[0] = 0;
        queue<int> que;
        que.push(0);
        while(!que.empty()){
            int now = que.front();
            que.pop();
            for(int e:G[now]){
                if(d[e] > d[now]+1){
                    d[e] = d[now]+1;
                    que.push(e);
                }
            }
        }
        
        rep(i,n){
            if(d[i]<INF){
                ll p=r[0], q=r[i];
                ll gg = __gcd(p,q);
                p/=gg;
                q/=gg;
                
                if(q==1) printf("%lld ", p);
                else printf("%lld/%lld ",p,q);
                
                if(d[i]%2==1) printf("counter");
                printf("clockwise\n");
            }
            else{
                printf("not moving\n");
            }        
        }
    }
    return 0;
}

