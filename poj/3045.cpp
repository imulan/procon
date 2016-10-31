#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

typedef pair<int,int> pi;
typedef pair<int,pi> P;

int main()
{
    int n;
    scanf(" %d", &n);

    vector<P> v(n);
    rep(i,n)
    {
        int w,s;
        scanf(" %d %d", &w, &s);
        v[i]=P(w+s,pi(-s,w));
    }
    sort(all(v));

    int ans=-1000000001;
    int sumw=0;
    rep(i,n)
    {
        int s=-v[i].se.fi;
        int w=v[i].se.se;
        ans=max(ans,sumw-s);
        sumw+=w;
    }
    printf("%d\n", ans);
    return 0;
}
