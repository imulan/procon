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

using pi = pair<int,int>;

int main()
{
    int n;
    cin >>n;
    vector<pi> t(n);
    rep(i,n) cin >>t[i].fi >>t[i].se;
    sort(all(t));

    string ans = "YES";
    int v1=-1,v2=-1;
    rep(i,n)
    {
        if(v1<t[i].fi) v1=t[i].se;
        else if(v2<t[i].fi) v2=t[i].se;
        else ans = "NO";
    }

    cout << ans << endl;
    return 0;
}
