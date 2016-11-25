#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

typedef pair<int,int> pi;
typedef pair<pi,int> P;

int main()
{
    int n,m;
    while(scanf(" %d %d",&n,&m),n)
    {
        vector<P> a(n);
        rep(i,n)
        {
            int d;
            scanf(" %d", &d);

            a[i] = P( pi((m/d)*d,d) , i+1);
        }

        sort(all(a));
        // rep(i,n) printf("%d %d : id=%d\n", a[i].fi.fi, a[i].fi.se,a[i].se);

        int ans=a[0].se;
        if(a[0].fi==a[1].fi) ans=n;
        printf("%d\n", ans);
    }
    return 0;
}
