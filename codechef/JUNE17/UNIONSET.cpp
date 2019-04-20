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
    int n,k;
    scanf(" %d %d", &n, &k);

    vector<int> sz(n);
    vector<vector<int>> a(n);
    rep(i,n)
    {
        scanf(" %d", &sz[i]);
        a[i] = vector<int>(sz[i]);
        rep(j,sz[i]) scanf(" %d", &a[i][j]);
        sort(all(a[i]));
    }

    vector<vector<int>> l(n);
    rep(i,n)
    {
        int idx=0;
        for(int j=1; j<=k; ++j)
        {
            if(idx<sz[i] && a[i][idx]==j) ++idx;
            else l[i].pb(j);
        }
    }

    rep(i,n) assert(sz[i]+l[i].size()==k);

    int ans = 0;
    rep(i,n)for(int j=i+1; j<n; ++j)
    {
        if(sz[i]+sz[j]<k) continue;
        if(sz[i]==k || sz[j]==k)
        {
            ++ans;
            continue;
        }

        int idx=0;
        int L=l[i].size();
        rep(x,sz[j])
        {
            if(idx==L) break;

            if(a[j][x]==l[i][idx]) ++idx;
            else if(a[j][x]<l[i][idx]) continue;
            else break;
        }

        if(idx==L) ++ans;
    }

    return ans;
}

int main()
{
    int T;
    cin >>T;
    while(T--) cout << solve() << endl;
    return 0;
}
