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
    ll a,b,n;
    cin >>a >>b >>n;

    //横向きに揃える
    if(a>b) swap(a,b);

    rep(i,n)
    {
        ll c,d;
        cin >>c >>d;
        if(c>d) swap(c,d);

        //平行におさまる
        if(a<c && b<d)
        {
            printf("YES\n");
            continue;
        }

        bool valid=false;
        if(a<=c)
        {
            double l=0, r=acos(-1)/2;
            rep(j,100)
            {
                double m=(l+r)/2;
                if(a*cos(m)+b*sin(m)<c) l=m;
                else r=m;
            }

            if(a*sin(l)+b*cos(l)<d) valid=true;
        }
        
        if(valid) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
