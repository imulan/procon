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

const int N = 2002;
const ll INF = LLONG_MAX/3;

int n,m;
ll a[N];
ll sa[N]={};

inline ll COST(int s, int num){
    ll ret = sa[s+num]-sa[s];
    ret *= num;
    return ret;
}

ll dp[N][N];
ll dfs(int x, int rem){
    if(x == n) return 0;
    if(rem == 0) return INF;
    if(dp[x][rem]>=0) return dp[x][rem];

    ll ret = INF;

    int l=1, r=n-x;
    while(r-l>5){
        int m1 = (2*l+r)/3, m2 = (l+2*r)/3;
        ll vl = dfs(x+m1,rem-1) + COST(x,m1);
        ll vr = dfs(x+m2,rem-1) + COST(x,m2);
        if(vl>vr) l=m1;
        else r=m2;
    }

    // printf(" %d,%d  [%d %d]\n",x,rem,l,r);
    for(int i=l;i<=r;++i) ret = min(ret, dfs(x+i,rem-1)+COST(x,i));

    return dp[x][rem] = ret;
}


int main(){
    cin >>n >>m;
    rep(i,n) cin >>a[i];

    sort(a,a+n);

    rep(i,n){
        sa[i+1] = sa[i]+a[i];
    }

    ll ans = INF;

    memset(dp,-1,sizeof(dp));
    cout << dfs(0,m) << endl;
    return 0;
}
