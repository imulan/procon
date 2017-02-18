#include <bits/stdc++.h>
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
    int n;
    scanf(" %d", &n);
    vector<int> a(n);
    rep(i,n) scanf(" %d", &a[i]);

    map<int,int> count, most_left;
    for(int i=n-1; i>=0; --i)
    {
        ++count[a[i]];
        most_left[a[i]]=i;
    }

    vector<ll> k,ct,ml;
    for(const auto &x:count)
    {
        int key = x.fi;
        k.pb(key);
        ct.pb(count[key]);
        ml.pb(most_left[key]);
    }

    int S = k.size();
    // rep(i,S) printf(" %d: count = %d, most_left = %d\n", k[i],ct[i],ml[i]);

    vector<ll> ans(n);

    for(int i=S-1; i>0; --i)
    {
        if(ml[i]==0) break;

        ll diff = k[i]-k[i-1];

        assert(diff>0);

        ans[ml[i]] += diff*ct[i];
        ct[i-1] += ct[i];
        ml[i-1] = min(ml[i-1],ml[i]);
        ct[i]=0;

        // printf("-----\n");
        // rep(j,S) printf(" %lld: count = %lld, most_left = %lld\n", k[j],ct[j],ml[j]);
        // printf("-----\n");
    }

    rep(i,S) ans[0]+=k[i]*ct[i];

    rep(i,n) printf("%lld\n", ans[i]);
    return 0;
}
