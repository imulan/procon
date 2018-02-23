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

const int N = 300000;
vector<int> G[N];
vector<int> nG[N];

void solve(){
    int n,m;
    scanf(" %d %d", &n, &m);

    vector<int> u(m),v(m);
    rep(i,m){
        scanf(" %d %d", &u[i], &v[i]);
        --u[i]; --v[i];
        G[u[i]].pb(v[i]);
        G[v[i]].pb(u[i]);
    }

    // 自身も追加
    rep(i,n){
        G[i].pb(i);
        sort(all(G[i]));
    }

    int K = 0;
    map<vector<int>,int> id2adj;
    vector<int> id(n);
    rep(i,n){
        if(!id2adj.count(G[i])) id2adj[G[i]] = K++;
        id[i] = id2adj[G[i]];
    }

    set<pair<int,int>> E;
    rep(i,m){
        int uu = id[u[i]], vv = id[v[i]];
        if(uu>vv) swap(uu,vv);
        if(uu != vv && !E.count({uu,vv})){
            nG[uu].pb(vv);
            nG[vv].pb(uu);
            E.insert({uu,vv});
        }
    }

    int start = -1;
    rep(i,K){
        if(nG[i].size()>2){
            printf("NO\n");
            return;
        }
        if(nG[i].size()<=1){
            start = i;
            break;
        }
    }
    if(start == -1){
        printf("NO\n");
        return;
    }

    int par = -1;
    int now = start;
    int l = 1;
    vector<int> label(K);
    while(1){
        label[now] = l++;
        bool found = false;
        for(int nx:nG[now]){
            if(nx != par){
                found = true;
                par = now;
                now = nx;
                break;
            }
        }
        if(!found) break;
    }

    vector<int> ans(n);
    rep(i,n){
        ans[i] = label[id[i]];
        if(ans[i]==0){
            printf("NO\n");
            return;
        }
    }

    printf("YES\n");
    rep(i,n) printf("%d%c", ans[i], " \n"[i==n-1]);
}

int main(){
    solve();
    return 0;
}
