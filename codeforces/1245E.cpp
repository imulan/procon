#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

const int L = 10;
const int N = 100;

int main(){
    int h[L][L];
    rep(i,L)rep(j,L) scanf(" %d", &h[i][j]);

    int f[L][L];
    int idx = 0;
    for(int i=L-1; i>=0; --i){
        int j = 0;
        int m = 1;
        if(i%2==0){
            j = L-1;
            m = -1;
        }

        rep(loop,L){
            f[i][j] = idx++;
            j += m;
        }
    }

    // pos if use ladder
    int nx[N];
    rep(i,L)rep(j,L) nx[f[i][j]] = f[i-h[i][j]][j];

    vector<double> E(N);
    for(int i=N-2; i>=0; --i){
        double v = 1;
        int ct = 0;
        for(int j=1; j<=6; ++j){
            if(i+j<N) v += min(E[i+j],E[nx[i+j]])/6;
            else ++ct;
        }

        E[i] = v*6/(6-ct);
    }
    printf("%.15f\n", E[0]);
    return 0;
}
