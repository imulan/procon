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

const int N = 22;

int n,m;
ll k;
ll a[N][N];

const int dx[2]={1,0}, dy[2]={0,1};

bool IN(int y, int x){
    return 0<=y && y<n && 0<=x && x<m;
}

map<ll,ll> ct[N][N];
void dfs1(int y, int x, ll v, int rem){
    if(rem==0){
        // printf(" DFS1 %d %d %lld\n", y,x,v);
        ++ct[y][x][v];
        return;
    }
    rep(i,2){
        int ny = y+dy[i], nx = x+dx[i];
        if(IN(ny,nx)) dfs1(ny,nx,v^a[ny][nx],rem-1);
    }
}

ll ans = 0;
void dfs2(int y, int x, ll v, int rem){
    if(rem==0){
        // printf(" DFS2 %d %d %lld\n", y,x,v);
        ll t = v^k;
        if(ct[y][x].count(t)) ans += ct[y][x][t];
        return;
    }
    rep(i,2){
        int ny = y-dy[i], nx = x-dx[i];
        if(IN(ny,nx)) dfs2(ny,nx,v^a[y][x],rem-1);
    }
}

int main(){
    cin >>n >>m >>k;
    rep(i,n)rep(j,m) cin >>a[i][j];

    int A = (n+m-2)/2, B = (n+m-2)-A;

    dfs1(0,0,a[0][0],A);
    dfs2(n-1,m-1,0,B);

    cout << ans << endl;
    return 0;
}
