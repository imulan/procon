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
int n,k;

ll dfs(int x, int r){
    if(r==0) return 1;

    ll ret = 0;
    for(int i=2; x*i<=n; ++i) ret += dfs(x*i, r-1);
    return ret;
}

int main(){
    cin >>n >>k;
    ll ans = 0;
    for(int i=1; i<=n; ++i) ans += dfs(i,k-1);
    cout << ans << endl;
    return 0;
}
