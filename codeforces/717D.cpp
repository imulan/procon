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

using vd = vector<double>;
using mat = vector<vd>;

mat mul(const mat &A, const mat &B){
    int n = A.size();
    mat C(n,vd(n));
    rep(i,n)rep(j,n)rep(k,n) C[i][j] += A[i][k]*B[k][j];
    return C;
}

vd mul(const mat &A, const vd &v){
    int n = A.size();
    vd b(n);
    rep(i,n)rep(j,n) b[i] += A[i][j]*v[j];
    return b;
}

mat mat_pow(const mat &A, int p){
    int n = A.size();
    mat P(n,vd(n));
    rep(i,n) P[i][i] = 1;

    mat X(A);
    while(p){
        if(p&1) P = mul(P,X);
        X = mul(X,X);
        p >>= 1;
    }

    return P;
}

const int M = 128;

int main(){
    int n,x;
    cin >>n >>x;
    vector<double> p(x+1);
    rep(i,x+1) cin >>p[i];

    mat A(M,vd(M));
    rep(mask,M){
        rep(i,x+1){
            int nmask = mask^i;
            A[mask][nmask] += p[i];
        }
    }

    A = mat_pow(A,n);

    vd start(M);
    start[0] = 1;
    vd res = mul(A, start);

    printf("%.10f\n", 1.0-res[0]);
    return 0;
}
