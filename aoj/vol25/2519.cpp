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

int n;
map<string,int> s, ct;

string f[4];

bool vis[4][4]={};
void dfs(int d, int y, int x, string now){
    if(s.count(now)) ++ct[now];
    if(d==8) return;

    for(int dy=-1; dy<=1; ++dy)for(int dx=-1; dx<=1; ++dx){
        int ny = y+dy , nx = x+dx;
        if(0<=ny && ny<4 && 0<=nx && nx<4 && !vis[ny][nx]){
            vis[ny][nx] = true;
            dfs(d+1,ny,nx,now+f[ny][nx]);
            vis[ny][nx] = false;
        }
    }
}

const int N = 10001;

vector<int> v[9];
int dp[N]={};

int main(){
    cin >>n;
    rep(i,n){
        string w;
        int score;
        cin >>w >>score;
        s[w] = score;
    }

    rep(i,4) cin >>f[i];

    rep(i,4)rep(j,4){
        vis[i][j] = true;
        dfs(1,i,j,string(1,f[i][j]));
        vis[i][j] = false;
    }

    for(const auto &p:ct){
        int sz = p.fi.size();
        rep(i,p.se) v[sz].pb(s[p.fi]);
    }

    int T;
    cin >>T;

    for(int i=1; i<=8; ++i){
        vector<int> x = v[i];
        sort(all(x),greater<int>());

        int X = x.size();
        if(X>10000/i) x.resize(10000/i);
        X = x.size();

        rep(j,X){
            for(int k=T-i; k>=0; --k){
                dp[k+i] = max(dp[k+i], dp[k]+x[j]);
            }
        }
    }

    int ans = 0;
    rep(i,T+1) ans = max(ans,dp[i]);
    cout << ans << endl;
    return 0;
}
