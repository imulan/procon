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

// const double EPS = 1e-8;
using vec = vector<int>;
using mat = vector<vec>;

// 行列の階数を求める
// 係数行列と拡大係数行列の階数が異なるときは不能
// 係数行列と拡大係数行列の階数が等しく、係数行列の階数と変数の個数が異なるときは不定
// 係数行列と拡大係数行列の階数と変数の個数がすべて等しいときは一意解が存在
int mat_rank(mat A){
    const int R = A.size(), C = A[0].size();
    int ret = 0;
    for(int i=0; ret<R&&i<C; ++i){
        // dbg(i);
        // rep(rr,R){
        //     rep(cc,C) printf("%2d", A[rr][cc]);
        //     puts("");
        // }

        int pivot = ret;
        for(int j=ret+1; j<R; ++j){
            if(abs(A[j][i]) > abs(A[pivot][i])) pivot = j;
        }
        swap(A[pivot], A[ret]);

        if(A[ret][i]==0) continue;

        // for(int k=C-1; k>=i; --k) A[ret][k] /= A[ret][i];
        for(int j=ret+1; j<R; ++j){
            for(int k=C-1; k>=i; --k) A[j][k] ^= A[ret][k]*A[j][i];
        }
        ++ret;
    }
    return ret;
}

// 連立方程式Ax=bを解く
// Aは正方行列を仮定
// 解無し、一意に定まらない : 長さ0のvector
vec gauss_jordan(const mat &A, const vec &b){
    int d = A.size();
    mat B(d, vec(d+1));
    rep(i,d){
        rep(j,d) B[i][j] = A[i][j];
        B[i][d] = b[i];
    }

    rep(i,d){
        int pivot = i;
        for(int j=i; j<d; ++j){
            if( abs(B[j][i]) > abs(B[pivot][i]) ) pivot = j;
        }
        swap(B[i], B[pivot]);

        // 解無し、一意に定まらない : 長さ0のvector
        if(B[i][i] == 0) return vec();

        // 注目する変数の係数を1にする
        // for(int j=i+1; j<=d; ++j) B[i][j] /= B[i][i];
        rep(j,d){
            if(i==j) continue;
            // j番目の式からi番目の変数を除去
            for(int k=i+1; k<=d; ++k) B[j][k] ^= B[j][i]*B[i][k];
        }
    }

    vec ret(d);
    rep(i,d) ret[i] = B[i][d];
    return ret;
}

mat mul(const mat &A, const mat &B){
    int n = A.size();
    mat ret(n,vec(n));
    rep(i,n)rep(j,n){
        rep(k,n) ret[i][j] ^= A[i][k]*B[k][j];
    }
    return ret;
}

mat mat_pow(const mat &A, int T){
    int n = A.size();
    mat ret(n,vec(n)),aa(A);
    rep(i,n) ret[i][i]=1;
    while(T){
        if(T&1) ret = mul(ret,aa);
        aa = mul(aa,aa);
        T>>=1;
    }
    return ret;
}

int main(){
    int n;
    scanf(" %d", &n);

    mat A(n, vec(n));
    rep(i,n)rep(j,n) scanf(" %d", &A[i][j]);

    vec v(n);
    rep(i,n) scanf(" %d", &v[i]);

    int T;
    scanf(" %d", &T);

    mat P = mat_pow(A,T);

    mat Pv(n, vec(n+1));
    rep(i,n){
        rep(j,n) Pv[i][j] = P[i][j];
        Pv[i][n] = v[i];
    }

    int rp = mat_rank(P), rpv = mat_rank(Pv);
    if(rp != rpv) printf("none\n");
    else{
        if(rp != n) printf("ambiguous\n");
        else{
            vec res = gauss_jordan(P,v);
            rep(i,n) printf("%d%c", res[i], " \n"[i==n-1]);
        }
    }
    return 0;
}
