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

int main(){
    int n;
    cin >>n;

    vector<int> ans;

    for(int i=2; i<=n; i+=2) ans.pb(i);
    for(int i=1; i<=n; i+=2) ans.pb(i);
    for(int i=2; i<=n; i+=2) ans.pb(i);

    int m = ans.size();
    cout << m << endl;
    rep(i,m) cout << ans[i] << " \n"[i==m-1];
    return 0;
}
