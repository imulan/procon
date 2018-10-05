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

int main(){
    int n,m;
    cin >>n >>m;

    mat Ab(n, vec(m+1));
    rep(i,m){
        int s,t;
        cin >>s >>t;
        --s;
        --t;

        Ab[s][i] = -1;
        Ab[t][i] = 1;
    }

    cout << m - mat_rank(Ab) << endl;
    return 0;
}
