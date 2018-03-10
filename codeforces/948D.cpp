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

const int SZ = 2;
struct Trie{
    vector<array<int,SZ>> nodes;
    vector<int> rem;

    Trie(){
        nodes.pb({});
        rem.pb(0);
    }

    void add(int x){
        int node_num = 0;
        for(int i=29; i>=0; --i){
            int b = x>>i&1;
            // 行き先が無いのでnodeを作成
            if(!nodes[node_num][b]){
                nodes[node_num][b] = nodes.size();
                nodes.pb({});
                rem.pb(0);
            }
            node_num = nodes[node_num][b];
            ++rem[node_num];
        }
    }

    // x との XOR を最小化出来る値を見つける
    int query(int x){
        int ret = 0;
        int node_num = 0;
        for(int i=29; i>=0; --i)
        {
            int b = x>>i&1;
            // bと同じ方向にあれば行きたい
            if(!nodes[node_num][b] || rem[nodes[node_num][b]]==0) b = !b;
            node_num = nodes[node_num][b];
            --rem[node_num];
            ret |= b<<i;
        }
        // printf("x %d ret %d\n", x,ret);
        return x^ret;
    }
};

int main(){
    int n;
    scanf(" %d", &n);

    vector<int> a(n),p(n);
    rep(i,n) scanf(" %d", &a[i]);
    rep(i,n) scanf(" %d", &p[i]);

    Trie t;
    rep(i,n) t.add(p[i]);
    rep(i,n) printf("%d%c", t.query(a[i]), " \n"[i==n-1]);
    return 0;
}
