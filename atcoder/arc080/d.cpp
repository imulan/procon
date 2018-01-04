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

const int dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1};

int main(){
    int h,w,n;
    cin >>h >>w >>n;

    queue<int> que;
    rep(i,n){
        int a;
        cin >>a;
        rep(j,a) que.push(i+1);
    }

    #define IN(y,x) (0<=y && y<h && 0<=x && x<w)
    vector<vector<int>> c(h,vector<int>(w,0));
    int y=0,x=0;
    int dir=0;
    while(!que.empty()){
        int col=que.front();
        que.pop();
        c[y][x] = col;

        rep(i,4){
            int ny=y+dy[dir], nx=x+dx[dir];
            if(!IN(ny,nx) || c[ny][nx]!=0) dir = (dir+1)%4;
            else{
                y = ny;
                x = nx;
                break;
            }
        }
    }

    rep(i,h)rep(j,w) printf("%d%c",c[i][j]," \n"[j==w-1]);
    return 0;
}
