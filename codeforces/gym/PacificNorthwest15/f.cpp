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

// TXRSZV7W



const int OMASK = ((1<<30)-1)^((1<<21)-1);
inline bool gameover(int mask){
    return (mask&OMASK) != 0;
}

int drop(int mask, char c, int d){



}

string s;
int n;

bool loop = false;

int dp[1<<21][20];
int dfs(int mask, int x){
    if(dp[mask][x]>=0) return dp[mask][x];

    if(dp[mask][x] == -2) loop = true;
    if(loop) return 0;

    dp[mask][x] = -2;

    int ret = 0;
    rep(i,4){
        int nmask = drop(mask, s[x], i);
        if(gameover(nmask)) continue;

        ret = max(ret, dfs(nmask, (x+1)%n)+1);
    }
    return dp[mask][x] = ret;
}

int main(){
    cin >>s;
    n = s.size();

    memset(dp,-1,sizeof(dp));
    int ans = dfs(0,0);

    if(loop) cout << "forever";
    else cout << ans;
    cout << "\n";
    return 0;
}
