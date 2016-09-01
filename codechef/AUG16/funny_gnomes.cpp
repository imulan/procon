#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define pb push_back
#define fi first
#define se second

typedef vector<int> vi;
typedef vector<vi> mat;

mat mul(const mat &a, const mat &b)
{
    int n=a.size();
    mat c(n,vi(n,0));
    rep(i,n)rep(j,n)rep(k,n) c[i][j]|=a[i][k]&b[k][j];
    return c;
}

vi mul_vec(const mat &a, const vi &b)
{
    int n=a.size();
    vi c(n,0);
    rep(i,n)rep(j,n) c[i]|=a[i][j]&b[j];
    return c;
}

int main()
{
    int n;
    cin >>n;
    mat g(n,vi(n));
    rep(i,n)rep(j,n) scanf(" %d",&g[i][j]);

    mat a[32];
    a[0]=mat(n,vi(n));
    rep(i,n)rep(j,n) a[0][i][j]=g[j][i];
    for(int i=1; i<32; ++i) a[i]=mul(a[i-1],a[i-1]);

    int m;
    cin >>m;
    rep(M,m)
    {
        int k,x;
        scanf(" %d %d", &k, &x);

        vi r(n,0);
        r[x-1]=1;
        rep(i,32) if(k>>i&1) r=mul_vec(a[i],r);

        int ct=0;
        vector<int> ans;
        rep(i,n)
        {
            if(r[i]==1)
            {
                ++ct;
                ans.pb(i+1);
            }
        }

        printf("%d\n", ct);
        if(ct==0) printf("-1\n");
        else
        {
            rep(i,ans.size())
            {
                if(i) printf(" ");
                printf("%d", ans[i]);
            }
            printf("\n");
        }
    }

    return 0;
}
