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

// 行列の階数を求める
// 係数行列と拡大係数行列の階数が異なるときは不能
// 係数行列と拡大係数行列の階数が等しく、係数行列の階数と変数の個数が異なるときは不定
// 係数行列と拡大係数行列の階数と変数の個数がすべて等しいときは一意解が存在
int mat_rank(mat A){
    const int R = A.size(), C = A[0].size();
    int ret = 0;
    for(int i=0; ret<R&&i<C; ++i){
        int pivot = ret;
        for(int j=ret+1; j<R; ++j){
            if(abs(A[j][i]) > abs(A[pivot][i])) pivot = j;
        }
        swap(A[pivot], A[ret]);

        if(abs(A[ret][i]) < EPS) continue;

        for(int k=C-1; k>=i; --k) A[ret][k] /= A[ret][i];
        for(int j=ret+1; j<R; ++j){
            for(int k=C-1; k>=i; --k) A[j][k] -= A[ret][k]*A[j][i];
        }
        ++ret;
    }
    return ret;
}
