#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const ll INF=1234567890123456LL;

//魔法をj回まで使えるときに、スライムiを入手するまでにかかる時間
ll cost[2000][2000]={0};

int main()
{
    int n;
    ll x;
    cin >>n >>x;

    vector<ll> a(n);
    rep(i,n) scanf(" %lld", &a[i]);

    rep(i,n) cost[i][0]=a[i];

    rep(i,n)for(int j=1; j<n; ++j)
    {
        //魔法をj回使う、つまりj個前の色
        int col=(i-j+n)%n;
        cost[i][j] = min(cost[i][j-1], a[col]);
    }

    // rep(i,n)rep(j,n) printf("cost[%d][%d]= %lld\n",i,j,cost[i][j]);

    ll ans=INF;
    rep(j,n)
    {
        ll getcost=0;
        rep(i,n) getcost+=cost[i][j];

        ans=min(ans, getcost+x*j);
    }
    cout << ans << endl;
    return 0;
}
