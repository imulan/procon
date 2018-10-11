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

const int INF = 19191919;

int main(){
    int n,s,t;
    while(scanf(" %d %d %d", &n, &s, &t),n){
        --s;
        --t;

        vector<int> q(n);
        rep(i,n) scanf(" %d", &q[i]);

        vector<vector<int>> a(n,vector<int>(n));
        rep(i,n)rep(j,n) scanf(" %d", &a[i][j]);

        vector<int> d(n,INF);
        d[t] = 0;
        queue<int> que;
        que.push(t);
        while(!que.empty()){
            int v = que.front();
            que.pop();
            rep(i,n){
                if(a[v][i]==0) continue;
                if(d[i] > d[v]+a[v][i]){
                    d[i] = d[v]+a[v][i];
                    que.push(i);
                }
            }
        }

        mat A(n,vec(n));
        vec b(n);
        rep(i,n){
            if(d[i]==INF || i==t){
                A[i][i] = 1;
                continue;
            }

            int ct = 0;
            rep(j,n)if(a[i][j]>0){
                if(q[i] == 1){
                    if(d[i] != a[i][j]+d[j]) continue;
                }
                ++ct;
            }

            A[i][i] = 1;
            rep(j,n)if(a[i][j]>0){
                if(q[i] == 1){
                    if(d[i] != a[i][j]+d[j]) continue;
                }
                A[i][j] -= 1.0/ct;
                b[i] += (double)a[i][j]/ct;
            }
        }

        vec res = gauss_jordan(A,b);
        assert(res.size()==n);
        printf("%.10f\n", res[s]);
    }
    return 0;
}
