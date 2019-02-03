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

const int B = 40;
ll ct[B][2]={};

int n;
ll k;

ll f(int d){
    return 1LL<<d;
}

ll dp[B][2];
ll dfs(int d, int s){
    if(d==-1) return 0;
    if(dp[d][s]>=0) return dp[d][s];

    ll ret = 0;
    if(s==0){
        if(k>>d&1){
            // 0
            ret = max(ret, dfs(d-1,1)+f(d)*ct[d][1]);
            // 1
            ret = max(ret, dfs(d-1,0)+f(d)*ct[d][0]);
        }
        else{
            // 0
            ret = max(ret, dfs(d-1,0)+f(d)*ct[d][1]);
        }
    }
    else{
        // 0,1
        ret = max(ret, dfs(d-1,1)+f(d)*max(ct[d][0],ct[d][1]));
    }
    return dp[d][s] = ret;
}

int main(){
    cin >>n >>k;

    rep(i,n){
        ll a;
        cin >>a;

        rep(j,40){
            int b = a>>j&1;
            ++ct[j][b];
        }
    }

    memset(dp,-1,sizeof(dp));
    cout << dfs(39,0) << endl;
    return 0;
}
