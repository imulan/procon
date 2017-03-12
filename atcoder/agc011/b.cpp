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
    int n;
    scanf(" %d", &n);
    vector<int> a(n);
    rep(i,n) scanf(" %d", &a[i]);
    sort(all(a));

    vector<ll> suma(n);
    suma[0]=a[0];
    for(int i=1; i<n; ++i) suma[i] = suma[i-1]+a[i];

    int ans=1;
    for(int i=n-2; i>=0; --i)
    {
        if(a[i+1]<=suma[i]*2) ++ans;
        else break;
    }

    printf("%d\n", ans);
    return 0;
}
