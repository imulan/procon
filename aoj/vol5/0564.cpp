#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

using pi = pair<int,int>;

int main()
{
    int n;
    scanf(" %d", &n);
    vector<pi> p(n);
    rep(i,n) scanf(" %d %d", &p[i].se, &p[i].fi);

    sort(all(p), greater<pi>());

    ll l=0, r=n+1;
    while(r-l>1)
    {
        ll m=(l+r)/2;

        ll sumA=0;
        priority_queue<int> A;
        rep(i,m)
        {
            sumA += p[i].se;
            A.push(p[i].se);
        }

        bool valid=(sumA<=m*p[m-1].fi);
        if(!valid)
        {
            for(int i=m; i<n; ++i)
            {
                int maxA = A.top();
                if(maxA > p[i].se)
                {
                    sumA = sumA - maxA + p[i].se;
                    A.pop();
                    A.push(p[i].se);
                }

                if(sumA<=m*p[i].fi)
                {
                    valid=true;
                    break;
                }
            }
        }

        if(valid) l=m;
        else r=m;
    }

    printf("%lld\n", l);
    return 0;
}
