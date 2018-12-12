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

const int N = 3020;
int b[N][N],w[N][N];

int ctb(int ly, int lx, int k){
    int ry = ly+k-1, rx = lx+k-1;
    int ret = b[ry][rx];
    if(lx-1>=0) ret -= b[ry][lx-1];
    if(ly-1>=0) ret -= b[ly-1][rx];
    if(lx-1>=0 && ly-1>=0) ret += b[ly-1][lx-1];
    return ret;
}

int ctw(int ly, int lx, int k){
    int ry = ly+k-1, rx = lx+k-1;
    int ret = w[ry][rx];
    if(lx-1>=0) ret -= w[ry][lx-1];
    if(ly-1>=0) ret -= w[ly-1][rx];
    if(lx-1>=0 && ly-1>=0) ret += w[ly-1][lx-1];
    return ret;
}

int main(){
    int n,k;
    scanf(" %d %d", &n, &k);

    int kk = 2*k;

    rep(i,n){
        int x,y;
        char c;
        scanf(" %d %d %c", &x, &y, &c);

        x %= kk;
        y %= kk;

        rep(dx,2)rep(dy,2){
            int nx = x + kk*dx;
            int ny = y + kk*dy;
            if(nx<N && ny<N){
                if(c == 'B') ++b[ny][nx];
                else ++w[ny][nx];
            }
        }
    }

    for(int i=1; i<N; ++i){
        b[0][i] += b[0][i-1];
        w[0][i] += w[0][i-1];

        b[i][0] += b[i-1][0];
        w[i][0] += w[i-1][0];
    }
    for(int i=1; i<N; ++i)for(int j=1; j<N; ++j){
        b[i][j] = b[i][j] + b[i-1][j]+b[i][j-1] - b[i-1][j-1];
        w[i][j] = w[i][j] + w[i-1][j]+w[i][j-1] - w[i-1][j-1];
    }

    auto fb = [&](int y, int x){
        return ctb(y,x,k) + ctb(y+k,x+k,k) + ctw(y+k,x,k) + ctw(y,x+k,k);
    };
    auto fw = [&](int y, int x){
        return ctw(y,x,k) + ctw(y+k,x+k,k) + ctb(y+k,x,k) + ctb(y,x+k,k);
    };

    int ans = 0;
    rep(i,k)rep(j,k){
        ans = max(ans, fb(i,j));
        ans = max(ans, fw(i,j));
    }
    cout << ans << endl;
    return 0;
}
