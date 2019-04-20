#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const int N=86400;
const int B=10800;

int ct[2*N]={0};

int main()
{
    int n;
    scanf(" %d", &n);

    vector<int> a(n),b(n);
    rep(i,n) scanf(" %d %d", &a[i], &b[i]);

    int e=a[0]%N;
    ++ct[e];
    ++ct[e+N];
    for(int i=1; i<n; ++i)
    {
        (e+=b[i-1]+a[i])%=N;
        ++ct[e];
        ++ct[e+N];
        // printf("e= %d\n", e);
    }

    int tmp=0;
    rep(i,B+1)
    {
        tmp+=ct[i];
    }

    int ans=tmp;
    for(int i=1; i<N; ++i)
    {
        tmp-=ct[i-1];
        tmp+=ct[i+B];
        ans=max(ans,tmp);
    }
    printf("%d\n", ans);
    return 0;
}
