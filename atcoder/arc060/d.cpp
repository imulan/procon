#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const ll LIM=1000000;

ll f(ll b, ll n)
{
    // printf("call f(%lld, %lld)\n", b,n);
    if(n<b) return n;
    else return f(b,n/b)+(n%b);
}

int main()
{
    ll n,s;
    cin >>n >>s;

    ll ans=-1;
    if(n==s) ans=n+1;
    else if(n>s)
    {
        if(n<LIM)
        {
            for(int b=2; b<=n; ++b)
            {
                if(f(b,n)==s)
                {
                    ans=b;
                    break;
                }
            }
        }
        else
        {
            ll now=n, a=1;
            while(now>LIM)
            {
                ll fnow=f(now,n);
                ll p=now-fnow-1, q=1+a;

                ll k=p/q;
                if(p%q!=0) ++k;

                if(fnow<=s && s<=fnow+a*k)
                {
                    if((s-fnow)%a==0)
                    {
                        ll kk=(s-fnow)/a;
                        ans=now-kk;
                    }
                }

                now-=k+1;
                ++a;
            }

            for(ll b=2; b<=now; ++b)
            {
                if(f(b,n)==s)
                {
                    ans=b;
                    break;
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}
