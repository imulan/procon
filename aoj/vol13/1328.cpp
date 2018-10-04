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

const double EPS = 1e-8;
using vec = vector<double>;
using mat = vector<vec>;

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
        if(abs(B[i][i]) < EPS) return vec();

        // 注目する変数の係数を1にする
        for(int j=i+1; j<=d; ++j) B[i][j] /= B[i][i];
        rep(j,d){
            if(i==j) continue;
            // j番目の式からi番目の変数を除去
            for(int k=i+1; k<=d; ++k) B[j][k] -= B[j][i]*B[i][k];
        }
    }

    vec ret(d);
    rep(i,d) ret[i] = B[i][d];
    return ret;
}

double f(const vec &a, double x){
    double ret = 0;
    rep(i,a.size()) ret += a[i]*pow(x,i);
    return ret;
}

int solve(int d){
    vector<double> v(d+3);
    rep(i,d+3) cin >>v[i];

    // 考慮しない2つを選択
    rep(i,d+3)rep(j,i){
        int row = 0;
        mat A(d+1,vec(d+1));
        vec b(d+1);

        rep(k,d+3){
            if(k==i || k==j) continue;

            rep(l,d+1) A[row][l] = pow(k,l);
            b[row] = v[k];
            ++row;
        }

        vec a = gauss_jordan(A,b);
        // printf(" %d %d\n", i,j);
        // dbg(a);
        if(a.size() > 0){
            int ct = 0;
            for(int idx:{i,j}){
                // printf(" %.10f %.10f  abs %.10f\n", f(a,idx), v[idx], abs(f(a,idx) - v[idx]));
                if( abs(f(a,idx) - v[idx]) > 1e-5 ) ++ct;
            }
            if(ct==1){
                if( abs(f(a,i) - v[i]) > 1e-5 ) return i;
                else return j;
            }
        }
    }
    assert(false);
    return -1;
}

int main(){
    int d;
    while(cin >>d,d) cout << solve(d) << endl;
    return 0;
}
