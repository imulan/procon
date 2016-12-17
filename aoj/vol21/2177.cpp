#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int main()
{
    cin.tie(0);ios::sync_with_stdio(false);
    
    ll p10[11];
    p10[0]=1;
    for(int i=1; i<11; ++i) p10[i]=p10[i-1]*10;

    ll n;
    int k;
    while(cin >>n >>k,n)
    {
        --n;

        ll d=1;
        while(n - 9*p10[d-1]*d >=0)
        {
            n-=9*p10[d-1]*d;
            ++d;
        }

        ll b=p10[d-1];

        b+=n/d;
        n-=(n/d)*d;

        string s="";
        for(ll i=b; i<b+100; ++i) s+=to_string(i);

        cout << s.substr(n,k) << '\n';
    }
    return 0;
}
