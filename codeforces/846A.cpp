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
    cin >>n;
    vector<int> a(n);
    rep(i,n) cin >>a[i];

    int one = 0;
    rep(i,n) one += a[i];
    int zero = n-one;

    int ans = max(one,zero);
    rep(i,n)if(a[i]==1)
    {
        int t = 0;
        rep(j,i) t += !a[j];
        for(int j=i; j<n; ++j) t += a[j];
        ans = max(ans,t);
    }
    return ans;
}

int main()
{
    cout << solve() << endl;
    return 0;
}
