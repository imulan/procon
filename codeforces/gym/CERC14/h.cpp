#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define repl(i,a,b) for(int (i)=(int)(a);(i)<(int)(b);++(i))
#define rep(i,n) repl(i,0,n)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

using pi = pair<int,int>;

const int LIM = 500;
bool vis[LIM][4][3];
bool OK[LIM];

struct State{
    int val,y,x;
};

int f[4][3]={
    {1,2,3},
    {4,5,6},
    {7,8,9},
    {-1,0,-1}
};

pi pos(int x){
    if(x==0) return {3,1};
    
    --x;
    return {x/3,x%3};
}

const int dx[3]={0,1,0};
const int dy[3]={0,0,1};

int main(){
    vis[0][0][0] = true;
    queue<State> que;
    que.push({0,0,0});
    while(!que.empty()){
        State now = que.front();
        que.pop();
        
        int v = now.val;
        pi c = {now.y,now.x};
        
        //printf(" %d:c(%d %d)\n", v,c.fi,c.se);
        rep(i,3){
            int ny = c.fi+dy[i], nx = c.se+dx[i];
            if(ny<4 && nx<3 && !vis[v][ny][nx]){
                vis[v][ny][nx] = true;
                que.push({v,ny,nx});
            }
            
            if(ny<4 && nx<3 && f[ny][nx]>=0){
                int nval = v*10 + f[ny][nx];
                if(nval<LIM && !vis[nval][ny][nx]){
                    vis[nval][ny][nx] = true;
                    que.push({nval,ny,nx});
                }            
            }
        }                
    }
    
    rep(i,LIM){
        rep(j,4)rep(k,3)if(vis[i][j][k]) OK[i] = true;
    }

    int T;
    scanf(" %d", &T);
    while(T--){
        int k;
        scanf(" %d", &k);
        
        int diff = LIM;
        int ans = -1;
        rep(i,LIM)if(OK[i]){
            int tmp = abs(k-i);
            if(diff > tmp){
                diff = tmp;
                ans = i;
            }
        }
        
        printf("%d\n",ans);
    }
    return 0;
}

