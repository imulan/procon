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


const int M = 20;
double p[M];
double pp[M];

const int N = 100010;
double dp[N];
bool vis[N];

int n;
double dfs(int d){
    if(vis[d]) return dp[d];
    if(d==n) return 0;

    double ret = 0;
    for(int j=1; j<M-1; ++j){
        if(d+j+1<=n) ret += p[j]*(1-pp[j+1])*(j + dfs(d+j+1));
        if(d+j==n) ret += p[j]*(j+ dfs(d+j));
    }

    vis[d] = true;
    return dp[d] = ret;
}

int main(){
    p[1] = 1;
    pp[1] = 1;
    for(int i=2; i<M; ++i){
        pp[i] = pp[i-1]/2;
        p[i] = p[i-1]*pp[i];
    }

    while(cin >>n,n){
        fill(vis,vis+N,false);
        printf("%.10f\n", dfs(0));
    }
    return 0;
}
