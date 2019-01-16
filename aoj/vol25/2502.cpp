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

const int N = 400;
const int INF = 19191919;
int dp[N];

int main(){
    int n;
    cin >>n;
    vector<int> s(n),l(n),p(n);
    rep(i,n) cin >>s[i] >>l[i] >>p[i];

    int m;
    cin >>m;
    vector<int> w(m);
    rep(i,m) cin >>w[i];

    rep(i,N) dp[i] = -INF;
    dp[0] = 0;

    rep(i,N){
        if(dp[i] < 0) continue;

        rep(j,n){
            for(int k=s[j]; k<=l[j]; ++k){
                if(i+k >= N) continue;
                dp[i+k] = max(dp[i+k], dp[i]+p[j]);
            }
        }
    }

    vector<int> a(m);
    rep(i,m){
        int ans = dp[w[i]];
        if(ans<0){
            cout << -1 << "\n";
            return 0;
        }
        a[i] = ans;
    }

    rep(i,m) cout << a[i] << "\n";
    return 0;
}
