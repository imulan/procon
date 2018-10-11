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

const int H = 19, W = 15;
string s[H];

const int INF = 19191919;
vector<pi> black;
map<pi,int> b2id;
int n;

map<pi,int> dp[1<<20];
int dfs(int mask, pi pos){
    if(pos.fi >=H) return 0;
    if(pos.se<0 || W<=pos.se) return INF;
    if(pos.fi == H-1) return 0;

    if(dp[mask].count(pos)) return dp[mask][pos];

    set<pi> rem;
    rep(i,n)if(!(mask>>i&1)) rem.insert(black[i]);

    int ret = INF;
    for(int dy=-1; dy<=1; ++dy)for(int dx=-1; dx<=1; ++dx){
        if(dy==0 && dx==0) continue;

        pi nx = pos;
        nx.fi += dy;
        nx.se += dx;
        if(!rem.count(nx)) continue;

        int nmask = mask;
        while(rem.count(nx)){
            nmask |= 1<<b2id[nx];
            nx.fi += dy;
            nx.se += dx;
        }

        ret = min(ret, dfs(nmask, nx)+1);
    }

    return dp[mask][pos] = ret;
}

int main(){
    rep(i,H) cin >>s[i];

    pi white;
    rep(i,H)rep(j,W){
        if(s[i][j]=='O') white = {i,j};
        if(s[i][j]=='X') black.pb({i,j});
    }
    n = black.size();

    rep(i,n) b2id[black[i]] = i;

    int ans = dfs(0, white);
    if(ans == INF) ans = -1;
    cout << ans << endl;
    return 0;
}
