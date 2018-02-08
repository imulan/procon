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

struct RollingHash{
    static const int MD = 2;
    static const vector<ll> hash_base, hash_mod;

    int n;
    vector<ll> hs[MD], pw[MD];

    RollingHash(){}
    RollingHash(const string &s){
        n = s.size();
        rep(i,MD){
            hs[i].assign(n+1,0);
            pw[i].assign(n+1,0);
            hs[i][0] = 0;
            pw[i][0] = 1;
            rep(j,n){
                pw[i][j+1] = pw[i][j]*hash_base[i] % hash_mod[i];
                hs[i][j+1] = (hs[i][j]*hash_base[i]+s[j]) % hash_mod[i];
            }
        }
    }

    // 1-index
    ll hash_value(int l, int r, int i){
        return ((hs[i][r] - hs[i][l]*pw[i][r-l])%hash_mod[i]+hash_mod[i])%hash_mod[i];
    }

    bool match(int l1, int r1, int l2, int r2){
        bool ret = true;
        rep(i,MD) ret &= (hash_value(l1-1,r1,i) == hash_value(l2-1,r2,i));
        return ret;
    }

    ll calc(int l, int r){
        ll ret=0;
        rep(i,MD) ret|=(hash_value(l-1,r,i)<<(i*30));
        return ret;
    }
};
const vector<ll> RollingHash::hash_base{1009,1021,1013};
const vector<ll> RollingHash::hash_mod{1000000009,1000000007,1000000021};

const int N = 5005;
int ct[N]={};

int n;
RollingHash h,rh;

int dp[N][N];
int p(int l, int r){
    if(dp[l][r]>=0) return dp[l][r];

    int ret = 0;
    if(h.calc(l,r) == rh.calc(n+1-r,n+1-l)) ret = 1;

    int L = r-l+1;
    L /= 2;
    if(L>0){
        if(h.calc(l,l+L-1) == h.calc(r-L+1,r)){
            int l_half = p(l,l+L-1), r_half = p(r-L+1,r);
            if(l_half>0 && l_half==r_half) ret = max(ret, l_half+1);
        }
    }

    return dp[l][r] = ret;
}

int main(){
    string s;
    cin >>s;
    n = s.size();

    string rs = s;
    reverse(all(rs));

    h = RollingHash(s);
    rh = RollingHash(rs);

    memset(dp,-1,sizeof(dp));
    for(int i=1; i<=n; ++i)for(int j=i; j<=n; ++j) ++ct[p(i,j)];

    for(int i=N-1; i>0; --i) ct[i-1] += ct[i];
    for(int i=1; i<=n; ++i) cout << ct[i] << " \n"[i==n];
    return 0;
}
