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

int main()
{
    int n;
    cin >>n;

    ll ct[101]={0};
    rep(i,n)
    {
        int a;
        scanf(" %d", &a);
        ++ct[a];
    }

    ll ans=0;
    for(int i=1; i<=100; ++i)
    for(int j=i+1; j<=100; ++j)
    for(int k=j+1; k<=100; ++k)
    {
        ans+=ct[i]*ct[j]*ct[k];
        ans%=mod;
    }

    cout << ans << endl;
    return 0;
}
