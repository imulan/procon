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

const int INF = 1919191;

int main(){
    int n;
    scanf(" %d", &n);

    vector<vector<int>> G(n);
    rep(i,n-1){
        int a,b;
        scanf(" %d %d", &a, &b);
        --a;
        --b;
        G[a].pb(b);
        G[b].pb(a);
    }

    vector<int> d,par;
    auto farthest = [&](int start){
        d = vector<int>(n,INF);
        par = vector<int>(n,-1);

        d[start] = 0;
        queue<int> que({start});
        while(!que.empty()){
            int v = que.front();
            que.pop();
            for(int e:G[v])if(d[e] > d[v]+1){
                que.push(e);
                par[e] = v;
                d[e] = d[v]+1;
            }
        }

        int md = -1;
        int ret = 0;
        rep(i,n){
            if(md < d[i]){
                md = d[i];
                ret = i;
            }
        }
        return ret;
    };

    int x = farthest(0);
    int y = farthest(x);
    int ans = d[y];

    d = vector<int>(n,INF);
    queue<int> que;

    int t = y;
    while(t!=-1){
        d[t] = 0;
        que.push(t);
        t = par[t];
    }

    while(!que.empty()){
        int v = que.front();
        que.pop();
        for(int e:G[v])if(d[e] > d[v]+1){
            que.push(e);
            d[e] = d[v]+1;
        }
    }

    int md = -1;
    int z = 0;
    rep(i,n)if(i!=x && i!=y){
        if(md < d[i]){
            md = d[i];
            z = i;
        }
    }
    ans += d[z];

    printf("%d\n%d %d %d\n", ans, x+1, y+1, z+1);
    return 0;
}
