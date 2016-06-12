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

ll INF=10000000000;

inline ll ab(ll x)
{
    return ((x>0)?x:-x);
}

int main()
{
    int n,m;
    while(cin >>n >>m,n|m)
    {
        vector<ll> s(n),d(m);
        rep(i,n) cin >>s[i];
        rep(i,m) cin >>d[i];

        sort(all(d));

        ll dp[33000];
        fill(dp,dp+33000,INF);
        dp[0]=0;

        rep(i,1<<n)
        {
            //現在のぬくもり値
            ll nuk=0;
            rep(j,n)
            {
                if(i>>j&1) nuk+=s[j];
            }


            //次にのせる布団
            rep(j,n)
            {
                //すでにある
                if(i>>j&1) continue;

                //次状態
                int nx=i+(1<<j);
                //次状態のぬくもり
                ll nxnuk=nuk+s[j];
                //printf("nuk=%lld nxnuk=%lld\n", nuk,nxnuk);

                ll add=0;
                rep(k,m)
                {
                    if(nuk<=d[k] && d[k]<=nxnuk)
                    {
                        add+=min(ab(d[k]-nuk),ab(nxnuk-d[k]));
                    }
                }

                //printf(" %d -> %d : add %lld\n",i,nx,add);
                dp[nx]=min(dp[nx],dp[i]+add);

                //printf("  dp[%d]=%lld\n", nx,dp[nx]);
            }
        }

        ll h=0;
        rep(i,n) h+=s[i];

        ll tmp=0;
        rep(i,m)
        {
            if(h<d[i]) tmp+=d[i]-h;
        }

        cout << dp[(1<<n)-1]+tmp << endl;
    }
    return 0;
}
