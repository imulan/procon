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
    int n,m;
    cin >>n >>m;

    vector<int> p(m);
    rep(i,m)
    {
        scanf(" %d", &p[i]);
        --p[i];
    }

    vector<int> a(n-1),b(n-1),c(n-1);
    rep(i,n-1) scanf(" %d %d %d", &a[i], &b[i], &c[i]);

    //鉄道iを使う回数
    int ct[100002]={0};
    rep(i,m-1)
    {
        int l=min(p[i],p[i+1]), r=max(p[i],p[i+1]);

        ++ct[l];
        --ct[r];
    }

    rep(i,n) ct[i+1]+=ct[i];

    ll ans=0;
    rep(i,n-1)
    {
        ll x=(ll)a[i]*ct[i];
        ll y=(ll)b[i]*ct[i]+c[i];
        ans+=min(x,y);
    }

    cout << ans << endl;
    return 0;
}
