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
const ll mod=1e9+7;

//i's divisor
vector<int> divisor[N+1];
//if i is power of a prime, restore the prime
int prime_pow[N+1]={0};

int main()
{
    int n;
    cin >>n;
    vector<int> a(n+1);
    for(int i=1; i<=n; ++i) scanf(" %d", &a[i]);

    for(ll i=1; i<=n; ++i)
    {
        // add divisor
        for(ll j=i; j<=n; j+=i) divisor[j].pb(i);

        // if i is prime:
        if(divisor[i].size()==2)
        {
            // powers of i restore prime i
            for(ll j=i*i; j<=n; j*=i) prime_pow[j]=i;
        }

        if(a[i]!=-1)
        {
            // i is determined,so divisors of i should be determined
            for(int d:divisor[i])
            {
                if(d==i) continue;
                if(a[d]!=-1 && a[d]!=a[i]%d)
                {
                    // a is not 'nice'
                    printf("0\n");
                    return 0;
                }

                a[d]=a[i]%d;
            }
        }
    }

    ll ans=1;

    for(ll i=1; i<=n; ++i)
    {
        if(divisor[i].size()==2)
        {
            if(a[i]==-1) (ans*=i)%=mod;
        }
        else
        {
            if(prime_pow[i]!=0 && a[i]==-1) (ans*=prime_pow[i])%=mod;
        }
    }

    cout << ans << endl;
    return 0;
}
