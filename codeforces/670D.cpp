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
    int n,k;
    cin >>n >>k;

    vector<ll> a(n),b(n);
    rep(i,n)
    {
        int t;
        scanf(" %d", &t);
        a[i]=t;
    }
    rep(i,n)
    {
        int t;
        scanf(" %d", &t);
        b[i]=t;
    }

    ll l=0,r=2000000001;
    ll med=(l+r)/2;

    bool end=false;
    while(1)
    {
        if(r-l<=1)
        {
            end=true;
            med=r;
        }

        med=(l+r)/2;
        bool ok=true;

        ll rem=k;
        rep(i,n)
        {
            ll need=b[i]-a[i]*med;
            if(need>=0) continue;

            rem+=need;

            if(rem<0)
            {
                ok=false;
                break;
            }
        }

        if(end)
        {
            if(!ok) med=l;
            break;
        }

        if(ok) l=med;
        else r=med;
    }

    cout << med << endl;

    return 0;
}
