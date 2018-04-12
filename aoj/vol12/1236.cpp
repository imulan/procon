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

const int N = 110;

vector<int> G[N];

void solve(){
    rep(i,N) G[i].clear();

    vector<int> r;
    while(1){
        int v;
        scanf(" %d", &v);
        if(v==0) break;
        r.pb(v);
    }
    int R = r.size();
    if(R==0){
        printf("1\n");
        return;
    }

    int num = 0;
    rep(i,R)if(r[i]>0) ++num;
    assert(num<N);

    // simulate dfs
    int ct = 0;
    int here = 0;
    vector<int> vis;
    vector<int> val;

    assert(r[0]>0);
    vis.pb(ct++);
    val.pb(r[0]);

    for(int i=1; i<R; ++i){
        while(val[here]<=0){
            vis.pop_back();
            if(vis.empty()) assert(false);

            here = vis.back();
        }

        if(r[i]>0){
            // dfs木の辺
            int par = vis.back();
            vis.pb(ct++);
            here = vis.back();

            val.pb(r[i]);
            --val[par];
            --val[here];
            G[par].pb(here);
            G[here].pb(par);
        }
        else{
            // 後退辺
            int V = vis.size();
            int idx = V-1 +r[i];
            assert(idx>=0);

            int par = vis[idx];
            --val[par];
            --val[here];
            G[par].pb(here);
            G[here].pb(par);
        }
    }

    rep(i,num){
        printf("%d", i+1);
        sort(all(G[i]));
        for(int j:G[i]) printf(" %d", j+1);
        printf("\n");
    }
}

int main(){
    int T;
    scanf(" %d", &T);
    while(T--) solve();
    return 0;
}
