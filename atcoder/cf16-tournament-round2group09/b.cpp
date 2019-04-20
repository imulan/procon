#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

typedef vector<ll> vi;

vi magic(const vi &v)
{
    int m=v.size();

    vi ret(m,0);
    ret[0]=v[0];
    for(int i=1; i<m; ++i) ret[i]=ret[i-1]+v[i];
    return ret;
}

void print(vector<vi> &v)
{
    int n=v.size();
    int m=v[0].size();

    rep(i,n)
    {
        rep(j,n)printf(" %d", v[i][j]);
        printf("\n");
    }
    printf("\n");

}

int main()
{
    int n,m;
    scanf(" %d %d", &n, &m);

    vector<vi> a(n,vi(m));
    rep(i,n)rep(j,m) scanf(" %lld", &a[i][j]);

    int ans=0;
    int now=1;
    while(now<n)
    {
        if(a[now]>a[now-1])
        {
            ++now;
            continue;
        }

        a[now]=magic(a[now]);
        ++ans;

        if(ans>10000)
        {
            ans=-1;
            break;
        }
    }
    printf("%d\n", ans);
    return 0;
}
