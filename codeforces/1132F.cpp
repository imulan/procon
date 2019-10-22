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

int n;
string s;

const int A = 26;
const int N = 505;
const int INF = 19191919;

int dp[N][N];
// [l,r)
int dfs(int l, int r){
    if(dp[l][r]>=0) return dp[l][r];
    if(l>=r) return 0;

    int ret = dfs(l+1,r)+1;

    char c = s[l];
    for(int i=l+1; i<r; ++i)if(s[i] == c){
        ret = min(ret, dfs(l+1,i)+dfs(i,r));
    }

    return dp[l][r] = ret;
}

int main(){
    cin >>n >>s;
    fill(dp[0], dp[N], -1);
    cout << dfs(0,n) << "\n";
    return 0;
}
