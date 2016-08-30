#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const ll mod=1e9+7;
const int N=200000;

int a[N];

int vis[N];
vector<int> cycles;
int c_idx=0;

//閉路検出
void dfs2(int x)
{
    ++cycles[c_idx];
    vis[x]=3;
    if(vis[a[x]]==3) return;
    dfs2(a[x]);
}

void dfs(int x)
{
    //まず頂点に入ったら暫定
    vis[x]=2;

    if(vis[a[x]]==0)
    {
        //次の頂点へ
        dfs(a[x]);
    }
    else if(vis[a[x]]==1)
    {
        //その先がもう処理終了している位置なのでここで打ち切り
        vis[x]=1;
        return;
    }
    else
    {
        //閉路検出
        cycles.pb(0);
        dfs2(x);
        ++c_idx;
    }

    //処理終了
    vis[x]=1;
}

int main()
{
    //2の累乗を計算しておく
    ll pw[N+1];
    pw[0]=1;
    for(int i=1; i<=N; ++i) pw[i]=(pw[i-1]*2)%mod;

    int n;
    scanf(" %d", &n);
    rep(i,n)
    {
        scanf(" %d", &a[i]);
        --a[i];
    }

    //visのフラグについて
    //0:まだ,1:完了,2:暫定到達,3:閉路検出
    memset(vis,0,sizeof(vis));
    rep(i,n)
    {
        if(vis[i]==0) dfs(i);
    }

    ll ans=1;

    int not_cycle=n;
    rep(i,c_idx)
    {
        (ans*=(pw[cycles[i]]-2+mod)%mod)%=mod;
        not_cycle-=cycles[i];
    }
    (ans*=pw[not_cycle])%=mod;

    cout << ans << endl;
    return 0;
}
