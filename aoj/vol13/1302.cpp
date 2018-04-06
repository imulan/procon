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

const int P = 12;
int pw[P];

int m,n;
vector<int> x;

int in(){
    string s;
    cin >>s;

    int ret = 0;
    rep(i,m)if(s[i]=='1') ret |= (1<<i);
    return ret;
}

int check(const vector<int> &s){
    int ct = 0;

    int must = 0;
    rep(i,m)if(s[i]==1) must ^= (1<<i);

    int cover = (1<<m)-1;
    rep(i,m)if(s[i]==2) cover ^= (1<<i);

    rep(i,n){
        int t = x[i];
        t ^= must;
        t &= cover;
        ct += !t;
    }
    return ct;
}

int make_mask(const vector<int> &s){
    int ret = 0;
    for(int i=m-1; i>=0; --i){
        ret *= 3;
        ret += s[i];
    }
    return ret;
}

int dp[540000];
int dfs(int mask){
    if(dp[mask]>=0) return dp[mask];

    vector<int> s(m);
    int tmp = mask;
    rep(i,m){
        s[i] = tmp%3;
        tmp /= 3;
    }

    if(check(s)<=1){
        int ct = 0;
        rep(i,m) ct += (s[i]!=2);
        return dp[mask] = ct;
    }

    int ret = 101010;

    // 次にどこを聞くか
    rep(i,m)if(s[i]==2){
        int zero,one;
        s[i] = 0;
        zero = make_mask(s);
        s[i] = 1;
        one = make_mask(s);
        s[i] = 2;
        ret = min(ret, max(dfs(zero),dfs(one)));
    }

    return dp[mask] = ret;
}

int main(){
    pw[0] = 1;
    for(int i=1; i<P; ++i) pw[i] = pw[i-1]*3;

    while(cin >>m >>n,m){
        x = vector<int>(n);
        rep(i,n) x[i] = in();

        memset(dp,-1,sizeof(dp));
        cout << dfs(pw[m]-1) << endl;
    }
    return 0;
}
