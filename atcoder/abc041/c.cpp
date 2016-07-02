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

typedef pair<int,int> pi;

int main()
{
    int n;
    cin >>n;

    vector<pi> v;

    rep(i,n)
    {
        int a;
        scanf(" %d", &a);
        v.pb(pi(-a,i+1));
    }

    sort(all(v));

    rep(i,n) printf("%d\n",v[i].se);
    return 0;
}
