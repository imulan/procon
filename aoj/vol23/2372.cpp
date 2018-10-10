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

const ll mod = 1e9+7;

using vec = vector<ll>;
using mat = vector<vec>;

vec mul(mat A, vec b){
    vec ret(2);
    rep(i,2)rep(j,2){
        (ret[i] += A[i][j]*b[j]) %= mod;
    }
    return ret;
}

mat mat_mul(mat A, mat B){
    mat C(2,vec(2));
    rep(i,2)rep(j,2){
        rep(k,2) (C[i][j] += A[i][k]*B[k][j]) %= mod;
    }
    return C;
}

mat mat_pow(mat A, ll n){
    mat ret({{1,0},{0,1}});
    while(n){
        if(n&1) ret = mat_mul(ret, A);
        A = mat_mul(A,A);
        n>>=1;
    }
    return ret;
}

// F1 * F_idx未満の値の個数
ll num(ll idx){
    ll a = idx-1;
    ll n = (a+1)/2;
    return n*(a-n+1);
}

ll F(ll idx){
    if(idx==1) return 1;
    if(idx==2) return 2;

    mat A({{1,1},{1,0}});
    vec b({2,1});
    A = mat_pow(A, idx-2);
    vec res = mul(A,b);
    return res[0];
}

int main(){
    ll k;
    cin >>k;

    // dbg(num(2000000000));
    ll ok = 1, ng = 2000000000;
    while(ng-ok>1){
        ll mid = (ok+ng)/2;
        if(num(mid) < k) ok = mid;
        else ng = mid;
    }

    k -= num(ok)+1;
    ll n = (ok+1)/2;

    ll p;
    if(k<=(n-1)/2) p = 2*k+1;
    else p = 2*(n-k);
    ll q = ok - (p-1);

    cout << (F(p)*F(q))%mod << endl;
    return 0;
}
