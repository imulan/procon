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
        int pivot = ret;
        for(int j=ret+1; j<R; ++j){
            if(abs(A[j][i]) > abs(A[pivot][i])) pivot = j;
        }
        swap(A[pivot], A[ret]);

        if(A[ret][i] == 0) continue;

        // for(int k=C-1; k>=i; --k) A[ret][k] /= A[ret][i];
        for(int j=ret+1; j<R; ++j){
            for(int k=C-1; k>=i; --k) A[j][k] ^= A[ret][k]&A[j][i];
        }
        ++ret;
    }
    return ret;
}

using pi = pair<int,int>;

int main(){
    int m,n,d;
    while(scanf(" %d %d %d", &m, &n, &d),m){
        auto ID = [&](int y, int x){
            return y*m + x;
        };

        auto get = [&](int idx){
            return pi(idx/m, idx%m);
        };

        auto dist = [&](pi p, pi q){
            return abs(p.fi-q.fi) + abs(p.se-q.se);
        };

        int sz = n*m;

        mat s(n,vec(m));
        mat a(sz, vec(sz));
        vec b(sz);
        rep(i,n)rep(j,m){
            scanf(" %d", &s[i][j]);
            b[ID(i,j)] = s[i][j];
        }

        rep(i,sz)rep(j,sz){
            if(i==j || dist(get(i), get(j)) == d) a[i][j] = 1;
        }

        mat ab(sz, vec(sz+1));
        rep(i,sz){
            rep(j,sz) ab[i][j] = a[i][j];
            ab[i][sz] = b[i];
        }

        printf("%d\n", mat_rank(a) == mat_rank(ab));
    }
    return 0;
}
