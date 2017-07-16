#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

using pi = pair<int,int>;

int main()
{
    int n,m;
    scanf(" %d %d", &n, &m);

    vector<pi> a(m);
    rep(i,m)
    {
        int x,y;
        scanf(" %d %d", &x, &y);
        a[i] = pi(x,y-1);
    }

    sort(all(a));

    vector<int> d(m),u(m);
    vector<int> last(n,-1);
    rep(i,m)
    {
        int y = a[i].se;

        int add=0;
        if(y-1>=0 && last[y-1]!=-1) add = u[last[y-1]];
        u[i] = 1+add;

        add=0;
        if(y+1<n && last[y+1]!=-1)add = d[last[y+1]];
        d[i] = 1+add;

        last[y] = i;
    }

    rep(i,n)
    {
        int ans = 1;
        if(last[i]!=-1) ans += d[last[i]];
        if(i-1>=0 && last[i-1]!=-1) ans += u[last[i-1]];

        printf("%d%c", ans, (i==n-1?'\n':' '));
    }
    return 0;
}
