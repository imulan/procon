#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define pb push_back
#define fi first
#define se second

const int N=10000;

int main()
{
    //素数表作成
    bool prime[N+1];
    fill(prime,prime+N+1,true);
    prime[0]=prime[1]=false;
    for(int i=2; i<=N; ++i)
    {
        if(prime[i]) for(int j=2; i*j<=N; ++j) prime[i*j]=false;
    }
    //素数リスト
    vector<int> p;
    rep(i,N+1) if(prime[i]) p.pb(i);

    int m,n;
    cin >>m >>n;
    vector<int> c(n);
    rep(i,n) cin >>c[i];

    //ちょうどi円消費した時に買えるカップ麺の個数の最大値(-1は買えない)
    int num[N+1];
    fill(num,num+N+1,-1);
    num[0]=0;
    for(int i=1; i<=m; ++i)
    {
        rep(j,n)
        {
            if(i-c[j]<0) continue;
            if(num[i-c[j]]>=0) num[i]=max(num[i],num[i-c[j]]+1);
        }
    }

    ll ans=0;
    rep(i,m+1) ans=max(ans,(ll)num[i]);

    //つぎに狙いに行こうとしている素数
    int pidx=p.size()-1;
    while(pidx>=0 && p[pidx]>m) --pidx;

    while(pidx>=0)
    {
        if(num[m-p[pidx]]>0) ans+=num[m-p[pidx]];
        --pidx;
    }

    cout << ans << endl;
    return 0;
}
