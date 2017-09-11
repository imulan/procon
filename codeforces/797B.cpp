#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

int solve()
{
    int n;
    scanf(" %d", &n);
    vector<int> a(n);
    rep(i,n) scanf(" %d", &a[i]);
    sort(all(a));

    int idx = 0;
    while(a[idx]<=0) ++idx;

    int ans = -191919;

    int ps = 0;
    for(int i=idx; i<n; ++i) ps += a[i];

    if(ps%2==1) ans = max(ans,ps);

    rep(i,idx)
    {
        int t = ps+a[i];
        if(abs(t)%2==1) ans = max(ans,t);
    }
    for(int i=idx; i<n; ++i)
    {
        int t = ps-a[i];
        if(abs(t)%2==1) ans = max(ans,t);
    }

    return ans;
}

int main()
{
    printf("%d\n", solve());
    return 0;
}
