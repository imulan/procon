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
    int n;
    cin >>n;

    vector<double> L(n);
    rep(i,n) scanf(" %lf", &L[i]);

    ll k;
    cin >>k;

    double l=0, r=1e9;

    rep(t,80)
    {
        double med=(l+r)/2;

        ll ct=0;
        rep(i,n) ct+=(ll)(L[i]/med);

        if(ct>=k) l=med;
        else r=med;

        //printf("%d: %.10lf %.10lf\n", t,l,r);
    }

    printf("%.10lf\n", l);
    return 0;
}
