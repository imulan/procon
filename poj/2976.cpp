#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int main()
{
    int n,k;
    while(scanf(" %d %d", &n, &k),n)
    {
        vector<int> a(n),b(n);
        rep(i,n) scanf(" %d", &a[i]);
        rep(i,n) scanf(" %d", &b[i]);

        double l=0,r=100.1;
        rep(T,300)
        {
            double m=(l+r)/2;

            vector<double> v(n);
            rep(i,n) v[i] = 100.0*a[i]-m*b[i];

            sort(all(v),greater<double>());

            double sum=0;
            rep(i,n-k) sum+=v[i];

            if(sum>=0) l=m;
            else r=m;
        }

        printf("%.0f\n", l);
    }
    return 0;
}
