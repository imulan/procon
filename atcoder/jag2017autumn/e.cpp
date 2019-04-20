#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb(x) push_back((x))
#define mp(x) make_pair((x))
#define fi first
#define se second

using P = pair<int,int>;

P memo[100005];
// <vを引き込んだときの部分問題のこたえ, 部分木サイズ>
int prev[100005];
// 上の部分問題

vector<P> ch[100005];

int cnt[100005];
// 部分木でサイズｋ以上の個数

vector<int> g[100005];

int n,k;

P dfs1(int v, int from){
    P ret = {0,1};
    vector<pair<P,int>> vec;
    for(auto to : g[v]) if(to != from){
        P r = dfs1(to, v);
        vec.push_back({r,to});
        ret.se += r.se;
    }
    cnt[v] = 0;
    for(auto p : vec) if(p.fi.se >= k) cnt[v]++;
    ret.fi = cnt[v];
    for(auto p : vec) {
        int current = cnt[v];
        if (p.fi.se >= k) current--;
        current += p.fi.fi;
        ret.fi = max(ret.fi, current);
        ch[v].push_back({current, p.se});
    }
    sort(all(ch[v]));
    return memo[v] = ret;
}

int dfs2(int v, int from, P par){
    // 持ってる値を使う場合
    int ret = memo[v].fi + (par.se>=k);
    // par側を使う場合
    ret = max(ret, par.fi + cnt[v]);

    cnt[v] += (par.se>=k);
    for(auto to : g[v]) if(to != from){
        P np = {0, n-memo[to].se};
        int x = cnt[v] - (memo[to].se>=k);
        np.fi = x;
        np.fi = max(np.fi, x - (par.se>=k) + par.fi);
        if (ch[v][0].se == to){
            if(ch[v].size()>=2){
                np.fi = max(np.fi, memo[v].fi + (par.se>=k) - (memo[to].se>=k) - (memo[ch[v][1].se].se>=k) );
            }
        }
        else {
            np.fi = max(np.fi, memo[v].fi + (par.se>=k) - (memo[to].se>=k));
        }
        cout << v << "-" << to << " " << np.fi << " " << np.se << endl;
        ret = max(ret, dfs2(to, v, np));
    }
cout << "exit" << v << " " << ret << endl;
    return ret;
}

int main()
{
    cin>>n>>k;
    rep(i,n-1){
        int a,b;
        cin>>a>>b;
        a--;b--;
        g[a].pb(b);
        g[b].pb(a);
    }

    dfs1(0, -1);

    cout << dfs2(0, -1, {0,0}) << endl;


    return 0;
}
