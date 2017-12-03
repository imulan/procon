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

int main()
{
    int n;
    cin >>n;
    vector<int> f(n);
    rep(i,n)rep(j,10)
    {
        int a;
        cin >>a;
        f[i]|=(a<<j);
    }

    vector<vector<int>> p(n,vector<int>(11));
    rep(i,n)rep(j,11) cin >>p[i][j];

    int ans = -1919191919;
    for(int mask=1; mask<(1<<10); ++mask)
    {
        int t = 0;
        rep(i,n)
        {
            int m = mask&f[i];
            t += p[i][__builtin_popcount(m)];
        }
        ans = max(ans,t);
    }

    cout << ans << endl;
    return 0;
}
