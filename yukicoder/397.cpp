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

typedef pair<int,int> pi;

int main()
{
    //in
    int n;
    cin >>n;
    vector<int> a(n);
    rep(i,n) cin >>a[i];

    //solve
    vector<pi> ans;
    rep(i,n)
    {
        int m=a[i];
        int idx=i;
        for(int j=i+1; j<n; ++j)
        {
            if(a[j]<m)
            {
                m=a[j];
                idx=j;
            }
        }

        if(idx!=i)
        {
            ans.pb(pi(i,idx));
            swap(a[i],a[idx]);
        }
    }

    //out
    cout << ans.size() << endl;
    rep(i,ans.size()) printf("%d %d\n", ans[i].fi, ans[i].se);
    cout << flush;

    //Dummy
    int D;
    cin >>D;
    return 0;
}
