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

const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,-1,0,1};

struct State{
    int pa,pb,pc;
};

const int N = 16*16;
const int INF = 19191919;
int dp[N][N][N];

int main(){
    int w,h,n;
    while(cin >>w >>h >>n,w){
        cin.ignore();
        vector<string> f(h);
        rep(i,h) getline(cin, f[i]);

        auto cv = [&](pi p){
            return p.fi*w+p.se;
        };

        int sa=0,sb=0,sc=0,ga=0,gb=0,gc=0;
        rep(i,h)rep(j,w){
            if(f[i][j]=='a') sa = cv({i,j});
            if(f[i][j]=='b') sb = cv({i,j});
            if(f[i][j]=='c') sc = cv({i,j});
            if(f[i][j]=='A') ga = cv({i,j});
            if(f[i][j]=='B') gb = cv({i,j});
            if(f[i][j]=='C') gc = cv({i,j});
        }

        auto cand = [&](int p){
            int y = p/w, x = p%w;

            vector<int> ret;
            ret.pb(p);

            rep(d,4){
                int ny = y+dy[d], nx = x+dx[d];
                if(0<=ny && ny<h && 0<=nx && nx<w && f[ny][nx]!='#') ret.pb(cv({ny,nx}));
            }
            return ret;
        };


        rep(i,N)rep(j,N)rep(k,N) dp[i][j][k] = INF;
        dp[sa][sb][sc] = 0;
        queue<State> que;
        que.push({sa,sb,sc});
        while(!que.empty()){
            State now = que.front();
            que.pop();

            vector<int> da = cand(now.pa), db = cand(now.pb), dc = cand(now.pc);

            for(int A:da)for(int B:db)for(int C:dc){
                if(B != 0){
                    if(B == A) continue;
                    if(now.pa == B && now.pb == A) continue;
                }
                if(C != 0){
                    if(C == A || C == B) continue;
                    if(now.pa == C && now.pc == A) continue;
                    if(now.pb == C && now.pc == B) continue;
                }

                if(dp[A][B][C] > dp[now.pa][now.pb][now.pc]+1){
                    dp[A][B][C] = dp[now.pa][now.pb][now.pc]+1;
                    que.push({A,B,C});
                }
            }
        }
        cout << dp[ga][gb][gc] << endl;
    }
    return 0;
}
