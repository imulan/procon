#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const int N=100000;

int n;
int p[N],sz[N]={},mx[N]={};

int main()
{
    scanf(" %d",&n);
    for(int i=1; i<n; ++i) scanf(" %d", &p[i]);

    for(int i=n-1; i>0; --i)
    {
        ++sz[i];
        sz[p[i]] += sz[i];
        mx[p[i]] = max(mx[p[i]], sz[i]);
    }

    rep(i,n) printf("%d\n", max(mx[i],n-sz[i]));
    return 0;
}
