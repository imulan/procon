#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const int N=5005;

int v[N][N]={}, d[N][N]={}, s[N][N];

int main()
{
    int n,m;
    scanf(" %d %d", &n, &m);
    while(m--)
    {
        int a,b,x;
        scanf(" %d %d %d", &a, &b, &x);
        --a;
        --b;

        ++v[a][b];
        --v[a+x+1][b];
        --d[a][b+1];
        ++d[a+x+1][b+x+2];
    }

    rep(i,N)for(int j=1; j<N; ++j) v[j][i] += v[j-1][i];
    rep(i,N)for(int j=1; i+j<N; ++j) d[i+j][j] += d[i+j-1][j-1];
    for(int j=1; 1+j<N; ++j) d[j][1+j] += d[j-1][1+j-1];

    rep(i,N)rep(j,N) s[i][j] = v[i][j]+d[i][j];
    rep(i,N)for(int j=1; j<N; ++j) s[i][j] += s[i][j-1];

    int ans=0;
    rep(i,n)rep(j,i+1) ans+=s[i][j]>0;
    printf("%d\n", ans);
    return 0;
}
