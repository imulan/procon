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

const int mod = 998244353;

const int N = 4004;
int dp[N][N];

int main(){
    string s;
    cin >>s;
    int n = s.size();

    vector<int> r,b;
    rep(i,n){
        if(s[i]=='0') rep(j,2) r.pb(i);
        else if(s[i]=='1'){
            r.pb(i);
            b.pb(i);
        }
        else rep(j,2) b.pb(i);
    }

    int R = r.size(), B = b.size();

    rep(i,R-1) r[i+1] = max(r[i+1], r[i]+1);
    rep(i,B-1) b[i+1] = max(b[i+1], b[i]+1);

    dp[0][0] = 1;
    rep(i,2*n)rep(rr,R+1)if(dp[i][rr]>0){
        int bb = i-rr;
        if(rr<R && r[rr]<=i) (dp[i+1][rr+1] += dp[i][rr]) %= mod;
        if(bb<B && b[bb]<=i) (dp[i+1][rr] += dp[i][rr]) %= mod;
    }
    cout << dp[2*n][R] << endl;
    return 0;
}
