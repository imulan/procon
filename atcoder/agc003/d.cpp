#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const int N=100000;
bool prime[N];
vector<int> p;
int P;

const ll INF=1234567890123LL;

int main()
{
    fill(prime,prime+N,true);
    prime[0]=prime[1]=false;
    for(int i=2; i<N; ++i)
    {
        if(prime[i]) for(int j=2; i*j<N; ++j) prime[i*j]=false;
    }
    rep(i,N) if(prime[i]) p.pb(i);
    P=p.size();

    //素数の2乗
    set<ll> sq;
    rep(i,P) sq.insert((ll)p[i]*p[i]);

    int n;
    scanf(" %d", &n);
    vector<ll> s(n);
    rep(i,n) scanf(" %lld", &s[i]);

    vector<ll> Norm(s), Pair(n,1);
    //s[i]^(1/3)以下のs[i]の素因数
    vector<int> f[100000];
    //Norm(s[i])の計算
    rep(i,n)
    {
        rep(j,P)
        {
            ll cube = (ll)p[j]*p[j]*p[j];
            if(cube>s[i]) break;
            while(Norm[i]%cube==0) Norm[i]/=cube;

            if(s[i]%p[j]==0)
            {
                f[i].pb(p[j]);
                if(Norm[i]%(p[j]*p[j])==0) Pair[i]*=p[j];
                else if(Norm[i]%p[j]==0) Pair[i]*=p[j]*p[j];
            }
        }
    }

    //Pair(s[i])の導出
    rep(i,n)
    {
        ll t=s[i];
        for(const auto &d:f[i]) while(t%d==0) t/=d;

        //素数の2乗
        if(sq.find(t)!=sq.end())
        {
            ll sqt=sqrt(t);

            //オーバーフローがないかチェック
            if(Pair[i] > LLONG_MAX/sqt) Pair[i]=INF;
            else  Pair[i]*=sqt;
        }
        else
        {
            if(t<N)
            {
                if(Pair[i] <= LLONG_MAX/t*t) Pair[i]*=t*t;
            }
            else
            {
                //大きすぎて収まらない
                if(t!=1) Pair[i]=INF;
            }
        }

        if(Pair[i]>10000000000LL) Pair[i]=INF;
    }

    int one=0;
    //normの値,個数
    map<ll,int> Norm_count;
    //norm->pair
    map<ll,ll> Norm_to_Pair;
    rep(i,n)
    {
        if(Norm[i]==1) one=1;
        else
        {
            if(Norm_count.find(Norm[i]) == Norm_count.end())
            {
                Norm_count[Norm[i]]=1;
                Norm_to_Pair[Norm[i]]=Pair[i];
            }
            else ++Norm_count[Norm[i]];
        }
    }

    //答えの導出
    int ans=one;
    set<ll> Not_use;

    for(const auto &x:Norm_count)
    {
        ll norm=x.fi;
        int ct=x.se;

        if(Not_use.find(norm) != Not_use.end()) continue;

        ll pair=Norm_to_Pair[norm];
        if(pair == INF) ans+=ct;
        else
        {
            if(Norm_count.find(pair) != Norm_count.end())
            {
                if(ct>=Norm_count[pair])
                {
                    ans+=ct;
                    Not_use.insert(pair);
                }
            }
            else ans+=ct;
        }
    }

    printf("%d\n", ans);
    return 0;
}
