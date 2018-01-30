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

const int N = 10010;
const int INF = 19191919;

inline int cost(int x){
    if(x<5) return x;
    return 1+x-5;
}

string n;
// (桁, 以上?, 繰り下がり?)
int dp[N][2][2];
int dfs(int d, int l, int s){
    if(d==0){
        if(s==0 && l==1) return 0;
        return INF;
    }
    if(dp[d][l][s]>=0) return dp[d][l][s];

    int ret = INF;
    rep(i,10){
        int diff = i - (n[d]-'0'+s);
        int nl = (diff>=0);
        int ns = 0;
        if(diff<0){
            ns = 1;
            diff += 10;
        }
        ret = min(ret, dfs(d-1,nl,ns)+cost(i)+cost(diff));
    }
    // printf(" %d %d %d :: %d\n",d,l,s,ret);
    return dp[d][l][s] = ret;
}

int main(){
    cin >>n;
    while(n.size()!=N) n = "0"+n;

    memset(dp,-1,sizeof(dp));
    cout << dfs(N-1,1,0) << endl;
    return 0;
}
