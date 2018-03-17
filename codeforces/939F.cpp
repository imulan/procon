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

const int N = 100010;
const int INF = 10101010;

int dp[N][2], nx[N][2];

int deq[N];
void slide(int x, int y, int D, int V, int A){
    int s=0, t=0;
    rep(i,N)if(i+D<N){
        while(s<t && dp[deq[t-1]][y] >= dp[i][y]) --t;
        deq[t++] = i;

        nx[i+D][x] = min(nx[i+D][x], dp[deq[s]][y]+A);

        if(deq[s] == i-V) ++s;
    }
}

int main(){
    int n,k;
    cin >>n >>k;
    vector<int> l(k+1),r(k+1);
    rep(i,k) cin >>l[i] >>r[i];
    l[k] = 2*n;

    vector<int> v(k),d(k+1);
    d[0] = l[0];
    rep(i,k){
        v[i] = r[i]-l[i];
        d[i+1] = l[i+1]-r[i];
    }

    fill(dp[0],dp[N],INF);
    dp[0][0] = 0;
    rep(i,k){
        fill(nx[0],nx[N],INF);
        rep(j,N){
            nx[j][0] = min(nx[j][0], dp[j][0]);
            if(j-v[i]-d[i+1]>=0) nx[j][1] = min(nx[j][1], dp[j-v[i]-d[i+1]][1]);
        }

        rep(x,2)rep(y,2){
            int D = 0;
            if(x==1) D = d[i+1];
            int A = 1;
            if(x==y) ++A;
            slide(x,y,D,v[i],A);
        }
        rep(x,N)rep(y,2) dp[x][y] = nx[x][y];
    }

    int ans = INF;
    rep(i,2) ans = min(ans,dp[n][i]);
    if(ans==INF) cout << "Hungry\n";
    else cout << "Full\n" << ans << "\n";
    return 0;
}
