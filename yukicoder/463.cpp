#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

typedef vector<double> Vec;
typedef vector<Vec> Mat;

const double eps=pow(2.0,-50);
const int N=200;

void gauss(Mat& A, Vec& B)
{
    int n=A.size();

    Vec b(n);
    rep(k,n-1)
    {
        double amax=fabs(A[k][k]);
        int ip=k;
        for(int i=k+1; i<n; ++i)
        {
            if(fabs(A[i][k]) > amax)
            {
                amax = fabs(A[i][k]);
                ip=i;
            }
        }

        if(amax < eps) printf("!!!error!!!\n");

        if(ip!=k)
        {
            for(int j=k; j<n; ++j) swap(A[k][j],A[ip][j]);
            swap(B[k],B[ip]);
        }

        for(int i=k+1; i<n; ++i)
        {
            double alpha = -A[i][k]/A[k][k];
            for(int j=k+1; j<n; ++j) A[i][j] += alpha*A[k][j];
            B[i] += alpha*B[k];
        }
    }

    B[n-1] = B[n-1]/A[n-1][n-1];
    for(int k=n-2; k>=0; --k)
    {
        double tmp = B[k];
        for(int j=k+1; j<n; ++j) tmp -= A[k][j]*B[j];
        B[k] = tmp/A[k][k];
    }
}

void test()
{
    int n=4;
    Mat A({{2,4,1,-3},{-1,-2,2,4},{4,2,-3,5},{5,-4,-3,1}});
    Vec B({0,10,2,6});

    rep(i,n)
    {
        rep(j,n) printf(" %5.1f", A[i][j]);
        printf(" : %5.1f\n", B[i]);
    }

    // ガウスの消去法
    gauss(A,B);

    printf("---AFTER---\n");
    rep(i,n)
    {
        rep(j,n) printf(" %5.1f", A[i][j]);
        printf(" : %5.1f\n", B[i]);
    }

}

int main()
{
    // test();

    int n,m;
    scanf(" %d %d", &n, &m);

    vector<int> c(n);
    for(int i=1; i<n-1; ++i) scanf(" %d", &c[i]);

    int f[N];
    rep(i,n) f[i]=i;
    for(int i=n; i<=n-2+m; ++i) f[i]=n-1-(i-n+1);


    double E[100][100];

    // スタート地点k
    rep(k,n-1)
    {
        Mat A(n,Vec(n,0));
        Vec B(n,0);

        // Aの構成
        rep(i,n) A[i][i]=1;
        rep(i,n-1)
        {
            for(int j=1; j<=m; ++j)
            {
                A[f[i+j]][i] -= 1.0/m;
            }
        }

        A[0][0]=0;
        A[0][k]=1;

        // Bの構成
        rep(i,n) B[i]=c[i];
        
        printf(" k= %d\n", k);
        rep(i,n)
        {
            rep(j,n) printf(" %5.1f", A[i][j]);
            printf(" : %5.1f\n", B[i]);
        }

        // ガウスの消去法
        gauss(A,B);

        printf("---AFTER---\n");
        rep(i,n)
        {
            rep(j,n) printf(" %5.1f", A[i][j]);
            printf(" : %5.1f\n", B[i]);
        }

        rep(i,n) E[k][i]=B[i];
    }

    rep(i,n)
    {
        rep(j,n) printf(" %10.5f", E[i][j]);
        printf("\n");
    }

    double ans=E[0][n-1];
    rep(i,n-1)
    {
        for(int j=1; j<=m; ++j)
        {
            int dst=f[i+j];
            ans = min(ans, E[0][i]+c[dst]+E[dst][n-1]);
        }
    }

    printf("%.10f\n", ans);
    return 0;
}
