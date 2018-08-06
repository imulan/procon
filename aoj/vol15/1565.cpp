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
using vi = vector<int>;

const int INF = 19191919;
const int dx[4]={1,-1,0,0}, dy[4]={0,0,1,-1};

int main(){
    int h,w;
    cin >>h >>w;
    vector<string> s(h);
    rep(i,h) cin >>s[i];

    pi start,goal;
    rep(i,h)rep(j,w){
        if(s[i][j] == 'S') start = {i,j};
        if(s[i][j] == 'G') goal = {i,j};
    }

    auto IN = [&](int y, int x){
        return 0<=y && y<h && 0<=x && x<w;
    };

    vector<vi> d(h,vi(w,INF));
    queue<pi> que;
    d[start.fi][start.se] = 0;
    que.push(start);

    while(!que.empty()){
        pi c = que.front();
        que.pop();
        int D = d[c.fi][c.se];

        // 移動( o:1 .:2 )
        rep(i,4){
            int ny=c.fi+dy[i], nx=c.se+dx[i];
            if(IN(ny,nx)){
                if(s[ny][nx]=='o'){
                    if(d[ny][nx] > D+1){
                        d[ny][nx] = D+1;
                        que.push({ny,nx});
                    }
                }
                else if(s[ny][nx]=='.' || s[ny][nx]=='G'){
                    if(d[ny][nx] > D+2){
                        d[ny][nx] = D+2;
                        que.push({ny,nx});
                    }
                }
            }
        }

        // スミを吐いてから移動 (2+距離)
        rep(i,4){
            for(int v=1; v<=3; ++v){
                int ny=c.fi+v*dy[i], nx=c.se+v*dx[i];
                if(!IN(ny,nx)) break;
                if(s[ny][nx]=='#') break;

                if(d[ny][nx] > D+2+v){
                    d[ny][nx] = D+2+v;
                    que.push({ny,nx});
                }
            }
        }
    }

    cout << d[goal.fi][goal.se] << endl;
    return 0;
}
