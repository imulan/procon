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

const int N = 3666;
const int INF = 19191919;
int dp[N];

void solve(){
    fill(dp, dp+N, INF);

    int n,t;
    scanf(" %d %d", &n, &t);
    vector<int> b(n);
    rep(i,n) scanf(" %d", &b[i]);

    queue<int> que;
    dp[0] = 0;
    que.push(0);
    while(!que.empty()){
        int now = que.front();
        que.pop();
        rep(i,n){
            int nt = now+b[i];
            if(nt<0) nt = 0;
            if(nt>3600) nt = 3600;

            if(dp[nt] > dp[now]+1){
                dp[nt] = dp[now]+1;
                que.push(nt);
            }
        }
    }

    int x,y;
    for(int i=t; i<=3600; ++i){
        if(dp[i]<INF){
            x = dp[i];
            y = i-t;
            break;
        }
    }
    printf("%d %d\n", x,y);
}

int main(){
    int T;
    scanf(" %d", &T);
    while(T--) solve();
    return 0;
}
