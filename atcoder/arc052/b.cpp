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

int main()
{
    int n,Q;
    cin >>n >>Q;

    vector<int> x(n),r(n),h(n);
    rep(i,n) scanf(" %d %d %d", &x[i], &r[i], &h[i]);

    rep(q,Q)
    {
        int A,B;
        scanf(" %d %d", &A, &B);

        double ans=0;

        rep(i,n)
        {
            if(B<=x[i] || x[i]+h[i]<=A) continue;

            int a=max(A,x[i]);
            int b=min(B,x[i]+h[i]);

            double ra=(double)r[i]*(x[i]+h[i]-a)/h[i];
            double rb=(double)r[i]*(x[i]+h[i]-b)/h[i];

            ans+=M_PI*ra*ra*(x[i]+h[i]-a)/3;
            ans-=M_PI*rb*rb*(x[i]+h[i]-b)/3;
        }

        printf("%.10lf\n", ans);
    }
    return 0;
}
