#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const int N=100000;
int f[30][N];

int main()
{
    int n;
    ll k;
    scanf(" %d %lld", &n, &k);

    vector<int> a;
    rep(i,n)if(i%2==0) a.pb(i);
    rep(i,n)if(i%2==1) a.pb(i);

    vector<int> nx;
    rep(i,(n+1)/2)
    {
        nx.pb(a[i]);
        if(n-1-i>i) nx.pb(a[n-1-i]);
    }
    reverse(all(nx));

    rep(i,n) f[0][i]=nx[i];
    for(int i=1; i<30; ++i)rep(j,n) f[i][j] = f[i-1][f[i-1][j]];

    vector<int> x(n);
    iota(all(x),0);

    rep(i,30)if(k>>i&1)
    {
        vector<int> y(n);
        rep(j,n) y[j] = f[i][x[j]];
        x=y;
    }

    rep(i,n)
    {
        if(i) printf(" ");
        printf("%d", x[i]+1);
    }
    printf("\n");
    return 0;
}
