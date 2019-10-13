#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

const int N = 20;
bool ok[1<<N];
int dp[1<<N];

int main(){
    cin.tie(0);ios::sync_with_stdio(false);

    string s;
    cin >>s;

    int n = s.size();
    vector<int> a(n);
    rep(i,n) a[i] = s[i]-'a';

    rep(i,n){
        int mask = 0;
        for(int j=i; j<min(n,i+N); ++j){
            if(mask>>a[j]&1) break;

            mask |= 1<<a[j];
            ok[mask] = true;
            dp[mask] = __builtin_popcount(mask);
        }
    }

    rep(mask,1<<N){
        rep(i,N)if(mask>>i&1){
            int nx = mask^(1<<i);
            dp[mask] = max(dp[mask], dp[nx]);
        }
    }

    int ans = 1;
    rep(mask,1<<N)if(ok[mask]){
        int rev = ((1<<N)-1)^mask;
        ans = max(ans, __builtin_popcount(mask)+dp[rev]);
    }
    cout << ans << "\n";
    return 0;
}
