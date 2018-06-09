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

int h,w;
string f[N];

int dp[N][N][N][N];
int Grundy(int ly, int lx, int ry, int rx){
    if(ry<ly || rx<lx) return 0;
    if(dp[ly][lx][ry][rx]>=0) return dp[ly][lx][ry][rx];

    set<int> s;
    for(int i=ly; i<=ry; ++i)for(int j=lx; j<=rx; ++j){
        if(f[i][j]=='.'){
            int g = Grundy(ly,lx,i-1,j-1)^Grundy(ly,j+1,i-1,rx)^Grundy(i+1,lx,ry,j-1)^Grundy(i+1,j+1,ry,rx);
            s.insert(g);
        }
    }

    int ret = 0;
    while(s.count(ret)) ++ret;

    return dp[ly][lx][ry][rx] = ret;
}

int main(){
    cin >>h >>w;
    rep(i,h) cin >>f[i];

    memset(dp,-1,sizeof(dp));
    int g = Grundy(0,0,h-1,w-1);
    cout << (g==0?"Second":"First") << endl;
    return 0;
}
