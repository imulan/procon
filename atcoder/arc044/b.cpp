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

const ll mod=1e9+7;

ll mod_pow(ll n, ll x)
{
    ll pw[40];
    pw[0]=n;
    for(int i=1; i<40; ++i) pw[i]=(pw[i-1]*pw[i-1])%mod;

    ll ret=1;
    rep(i,40) if(x>>i&1) (ret*=pw[i])%=mod;
    return ret;
}

int main()
{
    int n;
    cin >>n;
    vector<int> a(n);
    rep(i,n) scanf(" %d",&a[i]);

    bool valid=(a[0]==0);
    for(int i=1; i<n; ++i) if(a[i]==0) valid=false;

    //2のべき乗そ求めておく
    ll pw[100000];
    pw[0]=1;
    for(int i=1; i<100000; ++i)
    {
        pw[i]=pw[i-1]*2;
        pw[i]%=mod;
    }

    ll ans=0;

    if(valid)
    {
        //最大の深さ
        int deep=0;
        //その深さの頂点個数
        int ct[100000]={0};
        rep(i,n)
        {
            deep=max(deep,a[i]);
            ++ct[a[i]];
        }
        //最大の深さにたどり着く途中の深さの頂点がなかったらダメ
        rep(i,deep+1) if(ct[i]==0) valid=false;

        if(valid)
        {
            ans=1;
            for(int i=1; i<=deep; ++i)
            {
                //深さiと深さi-1間に張る辺の組み合わせ
                ll x=(pw[ct[i-1]]-1+mod)%mod;
                (ans*=mod_pow(x,ct[i]))%=mod;

                //深さi同士間に張る辺の組み合わせ
                ll y=(ll)ct[i]*(ct[i]-1)/2;
                (ans*=mod_pow(2,y))%=mod;
            }
        }
    }

    cout << ans << endl;
    return 0;
}
