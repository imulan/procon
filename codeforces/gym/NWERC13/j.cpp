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

const int N = 2500;
vector<int> G[N];
bool B[N];

string s;
int now;
void node(int &idx){
    assert(s[idx]=='(');
    ++idx;

    if(s[idx]=='B'){
        B[now] = true;
        idx += 2;
        return;
    }

    if(s[idx]==')'){
        ++idx;
        return;
    }

    int par = now;

    ++now;
    G[now].pb(par);
    G[par].pb(now);
    node(idx);

    ++now;
    G[now].pb(par);
    G[par].pb(now);
    node(idx);

    assert(s[idx]==')');
    ++idx;
}

int sumB[N];
void dfs(int v, int par){
    if(B[v]) ++sumB[v];
    for(int c:G[v])if(c!=par){
        dfs(c,v);
        sumB[v] += sumB[c];
    }
}

const int INF = 191919;
int dp[N][N];
int dfs2(int v, int par, int ball){
    if(dp[v][ball]>=0) return dp[v][ball];

    // printf("CALL %d %d\n", v,ball);

    vector<int> ch;
    for(int c:G[v])if(c!=par) ch.pb(c);

    if(ch.size()==0){
        if(ball>1) return INF;

        if(sumB[v]==1 && ball == 0) return 1;
        return 0;
    }

    int ret = INF;
    for(int i=ball/2-1; i<=ball/2+1; ++i){
        int j = ball-i;
        if(abs(i-j)>1) continue;

        // int cost = 0;
        // if(sumB[ch[0]]-i > 0) cost += sumB[ch[0]]-i;
        // if(sumB[ch[1]]-j > 0) cost += sumB[ch[1]]-j;

        ret = min(ret, dfs2(ch[0],v,i)+dfs2(ch[1],v,j));
    }

    return dp[v][ball] = ret;
}

int main(){
    while(cin >>s){
        rep(i,N) G[i].clear();
        fill(B,B+N,false);

        now = 0;
        int idx = 0;
        node(idx);

        fill(sumB,sumB+N,0);
        dfs(0,-1);

        memset(dp,-1,sizeof(dp));
        int ans = dfs2(0,-1,sumB[0]);
        if(ans == INF) printf("impossible\n");
        else printf("%d\n", ans);
    }
    return 0;
}
