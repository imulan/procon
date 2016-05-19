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

const int N=10000000;
bool p[N+1];

bool inline prime(ll x)
{
    for(ll i=2; i*i<=x; ++i)
    {
        if(x%i==0) return false;
    }
    return true;
}

bool valid(ll x)
{
    fill(p,p+N+1,true);
    p[0]=p[1]=false;
    for(ll i=2; i<=N; ++i)
    {
        if(p[i]) for(ll j=2; i*j<=N; ++j) p[i*j]=false;
    }


    for(ll i=2; i*i<=x; ++i)
    {
        if(x%i==0)
        {
            if(!p[i]) return true;
            else
            {
                if(!prime(x/i)) return true;
            }
        }
    }

    return false;
}

int main()
{
    ll n;
    cin >>n;

    string ans="NO";
    if(valid(n)) ans="YES";

    std::cout << ans << std::endl;
    return 0;
}
