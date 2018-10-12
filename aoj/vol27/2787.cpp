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

using pi = pair<int,int>;

const int N = 5005;
const int INF = 1234567;

// i番目,手前/真上は使用済み
int dp[N][2][2];

void init(){
    rep(i,N)rep(j,2)rep(k,2) dp[i][j][k] = INF;
}

vector<int> DG[10000];

int main(){
    int w,h,sp;
    scanf(" %d %d %d", &w, &h, &sp);

    int n;
    scanf(" %d", &n);
    rep(i,n){
        int x,y;
        scanf(" %d %d", &x, &y);
        DG[y].pb(x);
    }

    int m = (w+1)/2;

    sp -= m;
    if(sp<0){
        printf("-1\n");
        return 0;
    }

    int dog = 0;
    vector<int> D(w+1);
    for(int y=3; y<=h; y+=2){
        int dy = y-1;

        for(int x:DG[dy]) D[x] = 1;

        init();
        dp[0][1][0] = 0;
        rep(i,m)rep(j,2)rep(k,2)if(dp[i][j][k]<INF){
            // i-1
            if(i>0 && j==0){
                int dx = 2*i+1 - 1;
                dp[i+1][k][0] = min(dp[i+1][k][0], dp[i][j][k]+D[dx]);
            }

            // i
            if(k==0){
                int dx = 2*i+1;
                dp[i+1][1][0] = min(dp[i+1][1][0], dp[i][j][k]+D[dx]);
            }

            // i+1
            if(i+1<m){
                int dx = 2*i+1 + 1;
                dp[i+1][k][1] = min(dp[i+1][k][1], dp[i][j][k]+D[dx]);
            }
        }

        int add = INF;
        rep(i,2)rep(j,2) add = min(add, dp[m][i][j]);
        dog += add;

        for(int x:DG[dy]) D[x] = 0;
    }

    int normal = m*(h/2) - dog;
    // dbg(dog); dbg(normal);

    if(dog < sp){
        sp -= dog;
        dog = 0;
    }
    else{
        dog -= sp;
        sp = 0;
    }

    normal = max(0, normal - sp);

    printf("%d\n", 2*dog + normal);
    return 0;
}
