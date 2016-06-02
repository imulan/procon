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
    int T;
    cin >>T;
    rep(t,T)
    {
        ll k,c,s;
        cin >>k >>c >>s;

        printf("Case #%d:",t+1);

        if(s*c<k) printf(" IMPOSSIBLE\n");
        else
        {
            vector<ll> ans;

            for(ll i=1; i<=k; i+=c)
            {
                ll p=i;
                rep(j,c-1) p=(p-1)*k+min(i+j+1,k);
                ans.pb(p);
            }

            for(const auto &x:ans) cout << " " << x;
            cout << endl;
        }
    }
    return 0;
}
