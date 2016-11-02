#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

typedef vector<int> vi;
typedef vector<vi> Mat;

Mat mul(const Mat &a, const Mat &b, int mod)
{
    int n=a.size();
    Mat c(n,vi(n,0));
    rep(i,n)rep(j,n)rep(k,n) (c[i][j]+=a[i][k]*b[k][j])%=mod;
    return c;
}

Mat make(int n, int A, int B, int C)
{
    Mat r(n,vi(n,0));
    if(n==1) r[0][0]=B;
    else
    {
        r[0][0]=B;
        r[0][1]=C;
        r[n-1][n-2]=A;
        r[n-1][n-1]=B;
        for(int i=1; i<n-1; ++i)
        {
            r[i][i-1]=A;
            r[i][i]=B;
            r[i][i+1]=C;
        }
    }
    return r;
}

int main()
{
    int n,m,a,b,c,t;
    while(cin>>n>>m>>a>>b>>c>>t,n)
    {
        vector<int> s(n);
        rep(i,n) cin >>s[i];

        Mat P[31];
        P[0]=make(n,a,b,c);
        for(int i=1; i<31; ++i) P[i]=mul(P[i-1],P[i-1],m);

        Mat A(n,vi(n,0));
        rep(i,n) A[i][i]=1;
        for(int i=30; i>=0; --i)
        {
            if(t>=(1<<i))
            {
                A=mul(A,P[i],m);
                t-=(1<<i);
            }
        }

        rep(i,n)
        {
            int ans=0;
            rep(j,n) (ans+=A[i][j]*s[j])%=m;
            if(i) printf(" ");
            printf("%d", ans);
        }
        printf("\n");
    }
    return 0;
}
