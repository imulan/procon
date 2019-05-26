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

const int INF = 1010101010;
using pi = pair<int,int>;

int main(){
    int n;
    cin >>n;

    vector<pi> v(n);
    rep(i,n){
        int a,b;
        cin >>a >>b;
        if(a>b) swap(a,b);
        v[i] = {a,-b};
    }
    sort(all(v));

    vector<int> dp(n+1,INF);
    dp[0] = 0;
    rep(i,n){
        int x = -v[i].se;
        int idx = lower_bound(all(dp), x) - dp.begin();
        dp[idx] = x;
    }
    int ans = n;
    while(dp[ans]==INF) --ans;
    cout << ans << endl;
    return 0;
}
