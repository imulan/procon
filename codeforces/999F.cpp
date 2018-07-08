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

const int N = 505;
const int C = 5005;

int dp[N][C];

const int SZ = 100001;
int num[SZ], card[SZ];

int main(){
    int n,k;
    cin >>n >>k;

    rep(i,k*n){
        int c;
        cin >>c;
        ++card[c];
    }

    rep(i,n){
        int f;
        cin >>f;
        ++num[f];
    }

    vector<int> h(k+1);
    rep(i,k) cin >>h[i+1];

    rep(i,N-1)rep(j,C){
        rep(x,k+1){
            if(j+x<C) dp[i+1][j+x] = max(dp[i+1][j+x], dp[i][j]+h[x]);
        }
    }

    ll ans = 0;
    rep(i,SZ){
        ans += dp[num[i]][card[i]];
    }
    cout << ans <<endl;
    return 0;
}
