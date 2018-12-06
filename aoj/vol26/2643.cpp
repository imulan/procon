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

// NESW
const int dx[4]={0,1,0,-1};
const int dy[4]={-1,0,1,0};

const int INF = 19191919;

const int N = 50;
const int M = 1010;


int h,w;
string a[50];
string s;

int S;
int sy,sx,gy,gx;
int pa[M];

int dp[N][N][4][M];

struct State{
    int y,x,d,c;
};

bool check(int y, int x, int d, char cond, bool NOT){
    bool ret = true;
    if(cond=='N') ret = (d==0);
    if(cond=='E') ret = (d==1);
    if(cond=='S') ret = (d==2);
    if(cond=='W') ret = (d==3);
    if(cond=='C'){
        int ny = y+dy[d], nx = x+dx[d];
        ret = (a[ny][nx]=='#');
    }
    if(cond=='T') ret = true;

    if(NOT) ret = !ret;
    return ret;
}

void PROG(int &y, int &x, int &d, int &c, int &v);
void SENT(int &y, int &x, int &d, int &c, int &v);

bool loop = false;

void PROG(int &y, int &x, int &d, int &c, int &v, int ed){
    if(loop) return;
    while(c<ed){
        if(dp[y][x][d][c]<INF){
            loop = true;
            break;
        }
        SENT(y,x,d,c,v);
    }

    dp[y][x][d][c] = min(dp[y][x][d][c],v);
}

void SENT(int &y, int &x, int &d, int &c, int &v){
    dp[y][x][d][c] = min(dp[y][x][d][c],v);

    char o = s[c];
    if(o=='['){
        int pos = c;
        ++c;

        bool NOT = false;
        if(s[c]=='~'){
            NOT = true;
            ++c;
        }
        char cond = s[c];
        ++c;

        if(check(y,x,d,cond,NOT)){
            PROG(y,x,d,c,v,pa[pos]);
            if(loop) return;
        }
        else{
            c = pa[pos];
        }
        ++c;
    }
    else if(o=='{'){
        int pos = c;
        ++c;

        bool NOT = false;
        if(s[c]=='~'){
            NOT = true;
            ++c;
        }
        char cond = s[c];
        ++c;

        if(check(y,x,d,cond,NOT)){
            PROG(y,x,d,c,v,pa[pos]);
            if(loop) return;

            assert(s[c]=='}');
            c = pa[c];
        }
        else{
            c = pa[pos]+1;
        }
    }
    else{
        if(o=='^' || o=='v'){
            int mul = 1;
            if(o=='v') mul=-1;
            int ny = y+dy[d]*mul, nx = x+dx[d]*mul;
            if(a[ny][nx]!='#'){
                y = ny;
                x = nx;
            }
        }
        else{
            assert(o=='>' || o=='<');
            int add = 1;
            if(o=='<') add = 3;
            (d += add) %= 4;
        }
        ++c;
        ++v;
    }
}

int main(){
    cin >>h >>w;
    rep(i,h) cin >>a[i];
    cin >>s;
    S = s.size();

    rep(i,h)rep(j,w){
        if(a[i][j]=='s'){
            sy = i;
            sx = j;
        }
        if(a[i][j]=='g'){
            gy = i;
            gx = j;
        }
    }

    stack<int> st;
    rep(i,S){
        if(s[i]=='[' || s[i]=='{') st.push(i);
        if(s[i]==']' || s[i]=='}'){
            int idx = st.top();
            st.pop();
            pa[idx] = i;
            pa[i] = idx;
        }
    }

    rep(i,N)rep(j,N)rep(k,4)rep(l,M) dp[i][j][k][l] = INF;

    int py=sy, px=sx, pd=0, pc=0, pv=0;
    PROG(sy,sx,pd,pc,pv,S);

    int ans = INF;
    rep(i,4)rep(j,M) ans = min(ans, dp[gy][gx][i][j]);
    if(ans == INF) ans = -1;
    cout << ans << endl;
    return 0;
}
