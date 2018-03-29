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

const int INF = 1010101;
const int dx[4]={1,-1,0,0}, dy[4]={0,0,1,-1};

bool is_edge(int x, char c){
    if(x<2) return c=='-';
    return c=='|';
}

int main(){
    int h,w;
    char s,t;
    cin >>h >>w >>s >>t;

    vector<string> f(h);
    rep(i,h) cin >>f[i];

    pi start,goal;
    rep(i,h)rep(j,w){
        if(f[i][j] == s) start = {i,j};
        if(f[i][j] == t) goal = {i,j};
    }

    auto IN = [&](int y, int x){ return 0<=y && y<h && 0<=x && x<w; };

    vector<vector<int>> d(h,vector<int>(w,INF));
    queue<pi> que;
    d[start.fi][start.se] = 0;
    que.push(start);
    while(!que.empty()){
        pi now = que.front();
        que.pop();

        rep(i,4){
            int xx = now.se+2*dx[i], yy = now.fi+2*dy[i];
            if(IN(yy,xx) && is_edge(i,f[yy][xx])){
                while( !('A'<=f[yy][xx] && f[yy][xx]<='Z') ){
                    yy += dy[i];
                    xx += dx[i];
                }

                if(('A'<=f[yy][xx] && f[yy][xx]<='Z')){
                    if(d[yy][xx] > d[now.fi][now.se]+1){
                        d[yy][xx] = d[now.fi][now.se]+1;
                        que.push({yy,xx});
                    }
                }
            }
        }
    }

    cout << d[goal.fi][goal.se] << endl;
    return 0;
}
