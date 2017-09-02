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

    Trie(){
        nodes.pb({});
    }

    void add(int x){
        int node_num = 0;
        for(int i=29; i>=0; --i){
            int b = x>>i&1;
            // 行き先が無いのでnodeを作成
            if(!nodes[node_num][b]){
                nodes[node_num][b] = nodes.size();
                nodes.pb({});
            }
            node_num = nodes[node_num][b];
        }
    }

    // x との XOR を最大化出来る値を見つける
    int query(int x){
        int ret = 0;
        int node_num = 0;
        for(int i=29; i>=0; --i)
        {
            int b = x>>i&1;
            if(!nodes[node_num][!b]) b = !b;
            node_num = nodes[node_num][!b];
            ret |= (!b)<<i;
        }
        // printf("x %d ret %d\n", x,ret);
        return x^ret;
    }
};

int n,m;
vector<int> v,u;
vector<int> pv,pu;
int XOR(int t, int l, int r)
{
    if(t==0) return pv[r]^pv[l-1];
    else return pu[r]^pu[l-1];
}

int main()
{
    cin >>n >>m;

    v = vector<int>(n+1);
    u = vector<int>(m+1);
    rep(i,n) cin >>v[i+1];
    rep(i,m) cin >>u[i+1];

    pv = vector<int>(n+1);
    for(int i=1; i<=n; ++i) pv[i] = pv[i-1]^v[i];
    pu = vector<int>(m+1);
    for(int i=1; i<=m; ++i) pu[i] = pu[i-1]^u[i];

    int ans = 0;
    // 横方向を偶数長にする
    for(int lx=1; lx<=m; ++lx)for(int rx=lx+1; rx<=m; rx+=2)
    {
        ans = max(ans, XOR(1,lx,rx));
    }
    // 縦方向を偶数長にする
    for(int ly=1; ly<=n; ++ly)for(int ry=ly+1; ry<=n; ry+=2)
    {
        ans = max(ans, XOR(0,ly,ry));
    }

    // 両方奇数長のものを考える
    Trie trie;
    for(int ly=1; ly<=n; ++ly)for(int ry=ly; ry<=n; ry+=2)
    {
        trie.add(XOR(0,ly,ry));
    }
    for(int lx=1; lx<=m; ++lx)for(int rx=lx; rx<=m; rx+=2)
    {
        ans = max(ans,trie.query(XOR(1,lx,rx)));
    }

    cout << ans << endl;
    return 0;
}
