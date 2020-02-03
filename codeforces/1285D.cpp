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

const int SZ = 2;
struct Trie{
    vector<array<int,SZ>> nodes;
    vector<int> pr,dir;

    Trie(){
        nodes.pb({});
        pr.pb(0);
        dir.pb(0);
    }

    void add(int x){
        int node_num = 0;
        for(int i=30; i>=0; --i){
            int b = x>>i&1;
            // 行き先が無いのでnodeを作成
            if(!nodes[node_num][b]){
                int sz = nodes.size();
                nodes[node_num][b] = sz;
                nodes.pb({});
                pr.pb(1<<i);
                dir.pb(0);
            }
            node_num = nodes[node_num][b];
        }
    }

    int find_x(){
        int n = nodes.size();
        for(int i=n-1; i>=0; --i){
            int ct = 0;
            rep(j,2)if(!nodes[i][j]) ++ct;

            if(ct==0){
                int u = nodes[i][0], v = nodes[i][1];
                pr[i] |= min(pr[u], pr[v]);
                if(pr[u] > pr[v]) dir[i] = 1;
            }
            else{
                pr[i] = 0;
                if(nodes[i][0]){
                    pr[i] |= pr[nodes[i][0]];
                }
                if(nodes[i][1]){
                    pr[i] |= pr[nodes[i][1]];
                    dir[i] = 1;
                }
            }
        }

        int ret = 0;
        int now = 0;
        for(int i=30; i>=0; --i){
            int ct = 0;
            rep(j,2)if(!nodes[now][j]) ++ct;

            if(ct==0){
                if(!dir[now]) ret |= 1<<i;
            }
            else{
                if(dir[now]) ret |= 1<<i;
            }
            // if(dir[now] ^ (ct==0)) ret |= 1<<i;

            // printf(" %d :ct %d ",i, ct); dbg(dir[now]);
            now = nodes[now][dir[now]];
        }
        return ret;
    }
};

int main(){
    int n;
    cin >>n;

    Trie trie;
    vector<int> a(n);
    rep(i,n){
        cin >>a[i];
        trie.add(a[i]);
    }

    int x = trie.find_x();
    int ans = 0;
    rep(i,n) ans = max(ans, a[i]^x);
    cout << ans << "\n";
    return 0;
}
