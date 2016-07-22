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

ll min_factor(ll n)
{
    if(n%2==0) return 2;
    for(ll i=3; i*i<=n; ++i) if(n%i==0) return i;
    return n;
}

const int N=100000;

int main()
{
    bool prime[N+1];
    fill(prime,prime+N+1,true);
    prime[0]=prime[1]=false;
    for(int i=2; i<=N; ++i)
    {
        if(prime[i]) for(int j=2; i*j<=N; ++j) prime[i*j]=false;
    }
    //素数リスト作成
    vector<ll> p;
    rep(i,N) if(prime[i]) p.pb(i);
    int P=p.size();

    ll L,H;
    cin >>L >>H;

    int pidx=P-1;
    while(p[pidx]*p[pidx]>H) --pidx;

    ll pf=-1;
    ll ans=-1;
    for(int pp=pidx; pp>=0; --pp)
    {
        //最小の素因数が暫定の最大値より小さくなったらそれ以降は調べる必要性が無い
        if(p[pp]<pf) break;

        for(ll i=H/p[pp]; i>=max(p[pp],(L+p[pp]-1)/p[pp]); --i)
        {
            ll mul = p[pp]*i;
            ll minpf=min(p[pp],min_factor(i));
            if(pf<minpf || (pf==minpf&& ans<mul))
            {
                pf=minpf;
                ans=mul;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
