#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

typedef pair<double,int> P;
typedef pair<P,int> Pi;

int main()
{
    int n;
    scanf(" %d", &n);
    vector<int> t(n),d(n);
    rep(i,n) scanf(" %d %d", &t[i], &d[i]);

    vector<Pi> p(n);
    rep(i,n) p[i]=Pi(P((double)(-d[i])/t[i], t[i]),i);
    sort(all(p));

    ll ans=0;
    ll T=0;
    rep(i,n)
    {
        int id=p[i].se;
        ans+=T*d[id];
        T+=2*t[id];
    }

    cout << ans << endl;
    return 0;
}
