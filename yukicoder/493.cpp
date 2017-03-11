#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const ll INF = 1010101010101010101LL;
const ll mod = 1000000007;

ll mod_pow(ll x, ll n)
{
    ll pw[63];
    pw[0]=x;
    for(int i=1; i<63; ++i) pw[i]=(pw[i-1]*pw[i-1])%mod;

    ll ret=1;
    rep(i,63)
    {
        if(n>>i&1) (ret*=pw[i])%=mod;
    }
    return ret;
}

ll calc_length(int k)
{
    ll n=1;
    for(ll i=2; i<=k; ++i)
    {
        ll s=i*i;

        int ct=0;
        while(s>0)
        {
            s/=10;
            ++ct;
        }

        n = 2*n+ct;

        if(n>INF) return INF;
    }
    return n;
}

// 数列の要素数
ll calc_size(int K)
{
    ll ret=1;
    for(int i=2; i<=K; ++i)
    {
        ret = 2*ret+1;
        if(ret>INF) return INF;
    }
    return ret;
}

// 数列のindex番目までを文字にした時の文字の長さ
ll len(ll index, int K)
{
    ll ret=0;

    ll d=1;
    for(ll i=1; i<=K; ++i)
    {
        ll sq=i*i;
        ll l=0;
        while(sq>0)
        {
            sq/=10;
            ++l;
        }

        ll num = (index+d)/(d*2);
        if(num<0) num=0;

        ret += l*num;

        d*=2;
        if(d>index) break;
    }

    return ret;
}

void solve()
{
    int K;
    ll L,R;
    cin >>K >>L >>R;

    if(calc_length(K)<R)
    {
        printf("-1\n");
        return;
    }

    // 以下、解が存在する場合
    if(K==1)
    {
        printf("1 1\n");
        return;
    }

    // K>=2
    ll ans1=0, ans2=1;

    // 初めてL以上になるインデックスprを探す
    ll pl=0,pr=calc_size(K);
    while(pr-pl>1)
    {
        ll m=(pl+pr)/2;
        if(len(m,K)>=L) pr=m;
        else pl=m;
    }

    // 初めてR以下になるインデックスqlを探す
    ll ql=0,qr=calc_size(K)+1;
    while(qr-ql>1)
    {
        ll m=(ql+qr)/2;
        if(len(m,K)<=R) ql=m;
        else qr=m;
    }

    // printf("pr,ql (%lld, %lld)\n", pr,ql);

    // インデックスpr+1 ~ qlは全体が含まれるので、間を計算
    ll d=1;
    for(ll i=1; i<=K; ++i)
    {
        ll num = (ql+d)/(d*2) - (pr+1+d-1)/(d*2);
        if(num<0) num=0;

        ll sq=i*i;

        ll tsum=0;
        ll tprod=1;
        while(sq>0)
        {
            int v=sq%10;
            if(v==0) v=10;

            tsum+=v;
            (tprod*=v)%=mod;

            sq/=10;
        }

        ans1 += tsum*num;
        if(i>1)
        {
            ans2 *= mod_pow(tprod,num);
            ans2 %= mod;
        }
        d*=2;
        if(d>INF) break;
    }

    if(pr<=ql)
    {
        // インデックスpr
        ll div_count=1;
        ll tmp=pr;
        while(tmp%2==0)
        {
            tmp/=2;
            ++div_count;
        }
        string s=to_string(div_count * div_count);
        ll components = len(pr,K)-L+1;

        // cout << "pr:s = " << s << endl;
        // printf("components = %lld\n", components);

        int idx=s.size()-1;
        while(components>0)
        {
            int v=s[idx]-'0';
            if(v==0) v=10;

            ans1+=v;
            (ans2*=v)%=mod;

            --idx;
            --components;
        }

        // インデックスql+1
        // まずql+1が存在するか確認
        if(ql+1<=calc_size(K))
        {
            div_count=1;
            tmp=ql+1;
            while(tmp%2==0)
            {
                tmp/=2;
                ++div_count;
            }
            s=to_string(div_count * div_count);
            components = R-len(ql,K);

            // cout << "ql+1:s = " << s << endl;
            // printf("components = %lld\n", components);

            idx=0;
            while(components>0)
            {
                int v=s[idx]-'0';
                if(v==0) v=10;

                ans1+=v;
                (ans2*=v)%=mod;

                ++idx;
                --components;
            }
        }
    }
    else
    {
        ll div_count=1;
        ll tmp=pr;
        while(tmp%2==0)
        {
            tmp/=2;
            ++div_count;
        }
        string s=to_string(div_count * div_count);

        ll pre = len(ql,K);
        for(ll i=L; i<=R; ++i)
        {
            int v=s[i-pre]-'0';
            if(v==0) v=10;

            ans1+=v;
            (ans2*=v)%=mod;
        }
    }

    printf("%lld %lld\n", ans1, ans2);
}

void test()
{
    for(int k=1; k<=100000000; ++k)
    {
        printf("k = %d , len = %lld\n", k, calc_length(k));
        if(calc_length(k)>1000000000000000000LL) break;
    }
}

int main()
{
    // test();
    solve();
    return 0;
}
