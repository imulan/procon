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

using pi = pair<int,int>;
const int N = 100000;

vector<int> G[N];

// 帰ってくる必要がある/ない
pi dp1[N];
void dfs(int v, int par)
{
    int res = 0;
    for(int nx:G[v])if(nx!=par)
    {
        dfs(nx,v);
        res += dp1[nx].fi+2;
    }

    int notback = res;
    for(int nx:G[v])if(nx!=par)
    {
        int t = res;
        t += dp1[nx].se+1 - (dp1[nx].fi+2);
        notback = min(notback,t);
    }

    dp1[v] = {res,notback};
}

int ans[N];
void dfs2(int v, int par, pi d)
{

    // vを根としてみた時に、全ての部分木の情報を持つ
    vector<pair<pi,int>> c;
    // 子ども方向
    for(int nx:G[v])if(nx!=par) c.pb({dp1[nx],nx});
    // 親方向
    c.pb({d,-1});

    int C = c.size();
    // 全部の部分木に対して、「行って帰ってくる」ことにした場合のコスト
    int sum = 0;
    rep(i,C) sum += c[i].fi.fi+2;

    // secondを選ぶことによって得られる利益(少ないほうが嬉しい)
    // (利益,頂点)
    vector<pi> gain;

    // 頂点vに対する答えを計算する
    ans[v] = sum;
    // どの部分木を"帰らない"にするか全探索
    rep(i,C)
    {
        // "帰ってくる"から"帰らない"に切り替えたことによって変動するコスト
        int g = c[i].fi.se+1 - (c[i].fi.fi+2);

        ans[v] = min(ans[v],sum+g);
        gain.pb({g,c[i].se});
    }

    // 親方向の部分木の情報 d を更新しながら、子に伝播させる
    sort(all(gain));
    rep(i,C)
    {
        int nx = gain[i].se;
        if(nx==-1) continue;

        pi nd;
        // "帰ってくる"時は、行き先の部分木のぶんを除けば良い
        nd.fi = sum - (dp1[nx].fi+2);

        // "帰らない"時は、行き先の部分木が切り替えが一番得かそうでないかで場合わけが発生する
        // 一番得なら、その部分木は"帰らない"をえらんでいるはずなので次点で得なところを"帰らない"に切り替える
        // そうでなければ一番得な部分木を"帰らない"にすれば良い
        nd.se = nd.fi;
        if(i==0)
        {
            if(C>1) nd.se += gain[1].fi;
        }
        else nd.se += gain[0].fi;

        dfs2(nx,v,nd);
    }
}

int main()
{
    int n;
    scanf(" %d", &n);
    rep(i,n-1)
    {
        int u,v;
        scanf(" %d %d", &u, &v);
        --u;
        --v;
        G[u].pb(v);
        G[v].pb(u);
    }

    dfs(0,-1);
    dfs2(0,-1,{-2,-1});
    rep(i,n) printf("%d\n", ans[i]);
    return 0;
}
