#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const int N=25;

int main()
{
    int n;
    ll k;
    scanf(" %d %lld", &n, &k);
    vector<int> a(n);
    rep(i,n) scanf(" %d", &a[i]);

    int pw[N];
    pw[0]=1;
    for(int i=1; i<N; ++i) pw[i] = pw[i-1]*2;

    int l=0, r=10000001;
    while(r-l>1)
    {
        int m=(l+r)/2;
        ll ct=0;

        rep(i,n)
        {
            if(a[i]/m == 0) continue;

            int idx = upper_bound(pw,pw+N,a[i]/m)-pw;
            --idx;

            ll add = pw[idx];

            ll x=a[i]/pw[idx+1];
            ll y=(x+1)*pw[idx+1]-a[i];
            if(x+1>=m) add=max(add,pw[idx+1]-y);

            ct += add;
        }

        if(ct>=k) l=m;
        else r=m;
    }

    if(l==0) l=-1;
    printf("%d\n", l);
    return 0;
}
