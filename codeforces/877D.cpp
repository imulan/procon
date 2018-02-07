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

const int INF = 19191919;
const int dx[4]={1,-1,0,0}, dy[4]={0,0,1,-1};

int main(){
    int n,m,k;
    cin >>n >>m >>k;

    vector<string> s(n);
    rep(i,n) cin >>s[i];

    pi start,goal;
    int xx,yy;
    cin >>xx >>yy;
    start = {xx-1, yy-1};
    cin >>xx >>yy;
    goal = {xx-1, yy-1};

    auto IN = [=](int y, int x){ return 0<=x && x<m && 0<=y && y<n; };
    vector<vector<int>> d(n,vector<int>(m,INF));
    d[start.fi][start.se] = 0;
    queue<pi> que;
    que.push(start);
    while(!que.empty()){
        pi now = que.front();
        que.pop();
        // dbg(now);
        // printf(" d[now] = %d\n",d[now.fi][now.se]);
        rep(dir,4){
            for(int step=1; step<=k; ++step){
                int ny = now.fi + step*dy[dir];
                int nx = now.se + step*dx[dir];
                if(IN(ny,nx) && s[ny][nx]!='#'){
                    if(d[ny][nx]>d[now.fi][now.se]+1){
                        d[ny][nx] = d[now.fi][now.se]+1;
                        que.push({ny,nx});
                    }
                    else if(d[ny][nx]<d[now.fi][now.se]+1) break;
                }
                else break;
            }
        }
    }

    int ans = d[goal.fi][goal.se];
    if(ans == INF) ans = -1;
    cout << ans << endl;
    return 0;
}
