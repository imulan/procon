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

struct frac{
    ll n; //numerator
    ll d; //denominator
};

void printfrac(frac z)
{
    printf("%lld",z.n);
    if(z.d!=1) printf("/%lld",z.d);
    printf("\n");
}

inline ll gcd(ll x, ll y)
{
    if(x<y) swap(x,y);

    if(y==0) return x;
    else return gcd(y,x%y);
}

inline ll lcm(ll x, ll y)
{
    return x/gcd(x,y)*y;
}

frac add(frac a, frac b)
{
    ll G=lcm(a.d,b.d);
    ll g=a.n*(G/a.d)+b.n*(G/b.d);

    ll d=gcd(g,G);
    G/=d;
    g/=d;

    return frac{g,G};
}

int main()
{
    while(1)
    {
        string s;
        cin >>s;
        if(s=="#") break;

        int now=s.size()-1;
        ll pw=2;

        frac ans;

        //first word
        if(s[now]=='h')
        {
            now-=5;
            ans=frac{0,1};
        }
        else
        {
            now-=4;
            ans=frac{90,1};
        }

        //until end of word
        while(now>0)
        {
            if(s[now]=='h')
            {
                now-=5;
                ans=add(ans,frac{-90,pw});
            }
            else
            {
                now-=4;
                ans=add(ans,frac{90,pw});
            }
            pw*=2;
        }

        printfrac(ans);
    }
    return 0;
}
