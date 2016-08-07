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

bool prime[N+1];

int main()
{
    fill(prime,prime+N+1,true);
    prime[0]=prime[1]=false;
    for(int i=2; i<=N; ++i)
    {
        if(prime[i]) for(int j=2; i*j<=N; ++j) prime[i*j]=false;
    }

    vector<int> p;
    rep(i,N+1) if(prime[i]) p.pb(i);

    int n,L;
    cin >>n >>L;

    ll ans=0;
    for(int i=0; (n-1)*p[i]<=L; ++i) ans+=L-(n-1)*p[i]+1;
    cout << ans << endl;
    return 0;
}
