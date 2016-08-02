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

int main()
{
    int n;
    ll h,k;
    cin >>n >>h >>k;

    int a[100000];
    rep(i,n) scanf(" %d", &a[i]);

    ll now=0;
    int idx=0;
    ll ans=0;

    while(idx<n)
    {
        //入れられるだけ入れる
        while(idx<n && now+a[idx]<=h)
        {
            now+=a[idx];
            ++idx;
        }

        //次のが入るまで潰す
        int nx=h;
        if(idx<n) nx=a[idx];

        ll tmp=nx-h+now;
        ll t=tmp/k;
        if(tmp%k!=0) ++t;

        ans+=t;
        now-=t*k;
        if(now<0) now=0;
    }

    cout << ans << endl;
    return 0;
}
