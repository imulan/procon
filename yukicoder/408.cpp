#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

vector<int> G[20000];

int main()
{
    int n,m;
    scanf(" %d %d", &n, &m);
    vector<int> a(m),b(m);
    rep(i,m)
    {
        scanf(" %d %d", &a[i], &b[i]);
        --a[i];
        --b[i];
        G[a].pb(b);
        G[b].pb(a);
    }
    return 0;
}
