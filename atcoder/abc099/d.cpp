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

const int INF = INT_MAX;

int n,C;
int d[30][30];
int ct[3][30];
int cost[3][30];

bool used[30];
int dfs(int x){
    if(x==3) return 0;
    int ret = INF;
    rep(i,C)if(!used[i]){
        used[i] = true;
        ret = min(ret, dfs(x+1)+cost[x][i]);
        used[i] = false;
    }
    return ret;
}

int main(){
    cin >>n >>C;
    rep(i,C)rep(j,C) cin >>d[i][j];
    rep(i,n)rep(j,n){
        int c;
        cin >>c;
        --c;

        ++ct[(i+j)%3][c];
    }

    rep(i,3)rep(j,C){
        rep(k,C) cost[i][j] += d[k][j]*ct[i][k];
    }

    cout << dfs(0) << endl;
    return 0;
}
