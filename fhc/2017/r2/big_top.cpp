#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

typedef pair<ll,ll> pl;

double solve()
{
    int n;
    cin >>n;

    vector<ll> x(n),h(n);

    ll A,B,C;
    cin >>x[0] >>A >>B >>C;
    for(int i=1; i<n; ++i) x[i] = ((A*x[i-1]+B)%C)+1;

    cin >>h[0] >>A >>B >>C;
    for(int i=1; i<n; ++i) h[i] = ((A*h[i-1]+B)%C)+1;

    rep(i,n) printf(" x = %lld, h = %lld\n", x[i],h[i]);


    return 0;
}

int main()
{
    int T;
    cin >>T;
    rep(i,T) printf("Case #%d: %.10f\n", i+1, solve());
    return 0;
}
