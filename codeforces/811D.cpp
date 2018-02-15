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

int h,w;
string s[100];

bool swapLR = false, swapUD = false;
pi query(pi now, pi nx){
    char c;
    if(now.fi == nx.fi){
        if(now.se+1 == nx.se) c = 'R';
        else if(now.se-1 == nx.se) c = 'L';
        else assert(false);

        if(swapLR){
            if(c=='R') c='L';
            else c='R';
        }
    }
    else{
        if(now.fi+1 == nx.fi) c = 'D';
        else if(now.fi-1 == nx.fi) c = 'U';
        else assert(false);

        if(swapUD){
            if(c=='U') c='D';
            else c='U';
        }
    }

    cout << c << endl;
    cout << flush;

    int y,x;
    cin >>y >>x;
    return {y-1,x-1};
}

pi q(char c){
    cout << c << endl;
    cout << flush;

    int y,x;
    cin >>y >>x;
    return {y-1,x-1};
}

int main(){
    cin >>h >>w;
    rep(i,h) cin >>s[i];

    pi goal;
    rep(i,h)rep(j,w)if(s[i][j]=='F') goal = {i,j};

    pi now(0,0);
    if(h==1){
        rep(i,w){
            now = q('R');
            if(now == goal) return 0;
        }
        rep(i,w){
            now = q('L');
            if(now == goal) return 0;
        }
    }
    else if(w==1){
        rep(i,h){
            now = q('U');
            if(now == goal) return 0;
        }
        rep(i,h){
            now = q('D');
            if(now == goal) return 0;
        }
    }
    else{
        // h>=2, w>=2
        if(s[0][1]!='*'){
            // check LR
            now = q('R');
            if(now == pi(0,0)) swapLR=true;
            else now = q('L');

            // check UD
            rep(i,w){
                if(s[1][i]!='*'){
                    pi tt = now;
                    now = q('D');
                    if(tt == now) swapUD = true;
                    break;
                }
                now = query(now, {now.fi,now.se+1});
            }
        }
        else{
            assert(s[1][0]!='*');
            // check UD
            now = q('D');
            if(now == pi(0,0)) swapUD=true;
            else now = q('U');

            // check LR
            rep(i,h){
                if(s[i][1]!='*'){
                    pi tt = now;
                    now = q('R');
                    if(tt == now) swapLR = true;
                    break;
                }
                now = query(now, {now.fi+1,now.se});
            }
        }

        // BFS
        vector<vector<bool>> vis(h,vector<bool>(w));
        vector<vector<pi>> par(h,vector<pi>(w));

        queue<pi> que;
        vis[now.fi][now.se] = true;
        que.push(now);

        const int dx[4]={1,-1,0,0}, dy[4]={0,0,1,-1};
        auto IN = [=](int y, int x){ return 0<=y && y<h && 0<=x && x<w; };
        while(!que.empty()){
            pi cur = que.front();
            que.pop();
            rep(dir,4){
                int NY = cur.fi+dy[dir], NX = cur.se+dx[dir];
                if(IN(NY,NX) && s[NY][NX]!='*' && !vis[NY][NX]){
                    que.push({NY,NX});
                    vis[NY][NX] = true;
                    par[NY][NX] = cur;
                }
            }
        }

        vector<pi> route;
        pi tmp = goal;
        while(tmp != now){
            route.pb(tmp);
            tmp = par[tmp.fi][tmp.se];
        }
        reverse(all(route));

        for(const pi p:route){
            now = query(now, p);
        }
    }
    return 0;
}
