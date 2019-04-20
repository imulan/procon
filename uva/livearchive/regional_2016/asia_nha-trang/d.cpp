#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

using ll = __int128;

ll MOD;

// x*y % mod p (for large x,y)
// ll mod_mul(ll x, ll y, ll p){
//     x %= p;
//     y %= p;
//     ll res=0;
//     while(y){
//         if(y&1){
//         res += x;
//         if(res > p) res -= p;
//     }
//         x <<= 1;
//         if(x>p) x -= p;
//         y >>= 1;
//     }
//     return res;
// }

inline ll mod_mul(const ll x, const ll y, const ll p){
    return (x*y)%p;
}

ll mod_pow(ll x, ll n){
    ll ret = 1;
    while(n){
        if(n&1) ret = mod_mul(ret,x,MOD);
        x = mod_mul(x,x,MOD);
        n>>=1;
    }
    return ret;
}

using vl = vector<ll>;
using mat = vector<vl>;

mat mat_mul(const mat &A, const mat &B){
    int n=A.size(), m=B[0].size(), l=B.size();
    mat ret(n, vector<ll>(m, 0));
    rep(i,n) rep(k,l) if(A[i][k]!=0) rep(j,m){
        (ret[i][j] += mod_mul(A[i][k],B[k][j],MOD)) %= MOD;
    }
    return ret;
}

mat mat_pow(const mat &a, ll n){
    int A = a.size();
    mat x(a);

    mat ret(A,vl(A));
    rep(i,A) ret[i][i]=1;

    while(n){
        if(n&1) ret = mat_mul(ret,x);
        x = mat_mul(x,x);
        n>>=1;
    }
    return ret;
}

vl mul(const mat &a, const vl &b){
    int n = a.size();
    vl ret(n);
    rep(i,n)rep(j,n) (ret[i] += mod_mul(a[i][j],b[j],MOD)) %= MOD;
    return ret;
}

long long solve(){
    long long n,m;
    string s;
    cin >>n >>m >>s;

    MOD = m;
    int S = s.size();

    mat A(S+1,vl(S+1));

    rep(i,S){
        rep(j,26){
            char c = 'a'+j;
            string t = s.substr(0,i);
            t += c;

            int L = i+1;
            while(1){
                string tmp = s.substr(0,L);
                string tt = t.substr(i+1-L,L);
                // dbg(L);dbg(tmp);dbg(tt);
                if(tmp==tt) break;
                --L;
            }
            // printf("(%d,%c) ::  %d\n",i,c,L);
            ++A[L][i];
        }
    }
    A[S][S] = 26;

    A = mat_pow(A,n);

    vl v(S+1,0);
    v[0]=1;
    v = mul(A,v);
    return v[S];
}

int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    int T;
    cin >>T;
    while(T--) cout << solve() << endl;
    return 0;
}
