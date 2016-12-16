#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

// 原点とのチェビシェフ距離
inline int Chebyshev_dist(int x, int y)
{
    return max(x,y);
}

const int INF=1010101010;

int solve()
{
    int n,x,y;
    cin >>n;
    vector<int> d(n);
    rep(i,n) cin >>d[i];
    cin >>x >>y;

    x=abs(x);
    y=abs(y);
    sort(all(d),greater<int>());

    int D=Chebyshev_dist(x,y);

    if(x==0 && y==0) return 0;
    rep(i,n)if(D==d[i]) return 1;
    if(d[0]>D) return 2;
    return (D+d[0]-1)/d[0];
}

int main()
{
    printf("%d\n", solve());
    return 0;
}
