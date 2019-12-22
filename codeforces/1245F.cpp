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

const int N = 31;
int L[N],R[N];

ll dp[N][4][4];
ll dfs(int d, int lf, int rf){
    if(d==-1) return 1;
    if(dp[d][lf][rf]>=0) return dp[d][lf][rf];

    int l[2],r[2];
    rep(i,2){
        l[i] = (lf>>i)&1;
        r[i] = (rf>>i)&1;
    }

    ll ret = 0;
    rep(x,3){
        int b[2];
        rep(i,2) b[i] = (x>>i)&1;

        bool valid = true;
        int nl[2],nr[2];
        rep(i,2){
            nl[i] = l[i];
            nr[i] = r[i];

            if(!l[i]){
                if(L[d]==1 && b[i]==0) valid = false;
                if(L[d]==0 && b[i]==1) nl[i] = 1;
            }
            if(!r[i]){
                if(R[d]==0 && b[i]==1) valid = false;
                if(R[d]==1 && b[i]==0) nr[i] = 1;
            }
        }
        if(!valid) continue;

        int nlf = 0, nrf = 0;
        rep(i,2){
            nlf |= (nl[i]<<i);
            nrf |= (nr[i]<<i);
        }

        ret += dfs(d-1, nlf, nrf);
    }

    return dp[d][lf][rf] = ret;
}

ll solve(){
    int l,r;
    cin >>l >>r;

    rep(i,N) L[i] = (l>>i)&1;
    rep(i,N) R[i] = (r>>i)&1;

    memset(dp,-1,sizeof(dp));
    return dfs(N-1,0,0);
}

int main(){
    int T;
    cin >>T;
    while(T--) cout << solve() << "\n";
    return 0;
}
