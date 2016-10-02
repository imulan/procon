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
    int n,k,x;
    scanf(" %d %d %d", &n, &k, &x);
    --x;

    vector<int> a(k),b(k),c(n);
    rep(i,k)
    {
        if(i!=x) scanf(" %d %d", &a[i], &b[i]);
        else
        {
            char aa,bb;
            scanf(" %c %c", &aa, &bb);
            a[i]=b[i]=0;
        }
        --a[i];
        --b[i];
    }
    rep(i,n) scanf(" %d", &c[i]);

    vector<int> start(n);
    rep(i,n) start[i]=i+1;

    rep(i,x) swap(start[a[i]],start[b[i]]);
    for(int i=k-1; i>x; --i) swap(c[a[i]],c[b[i]]);

    vector<int> ans;
    rep(i,n)
    {
        if(start[i]!=c[i]) ans.pb(i+1);
    }

    printf("%d %d\n", ans[0], ans[1]);
    return 0;
}
