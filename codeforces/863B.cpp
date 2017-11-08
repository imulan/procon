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
    vector<int> w(2*n);
    rep(i,2*n) cin >>w[i];

    sort(all(w));

    int ans = 19191919;
    rep(i,2*n)rep(j,i)
    {
        vector<int> r;
        rep(k,2*n)if(k!=i && k!=j) r.pb(w[k]);

        int t = 0;
        rep(k,n-1) t += r[2*k+1]-r[2*k];
        ans = min(ans,t);
    }

    cout << ans << endl;
    return 0;
}
