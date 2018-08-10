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

const int N = 1010;
// 左,上,右,下に、いくつあるか
int a[N][N][4];

int yy[N][N], xx[N][N];

int main(){
    int h,w;
    cin >>h >>w;
    vector<string> s(h);
    rep(i,h) cin >>s[i];

    auto IN = [&](int y, int x){
        return 0<=y && y<h && 0<=x && x<w;
    };

    memset(a,-1,sizeof(a));
    rep(y,h)rep(x,w)if(s[y][x]=='*'){
        rep(k,4) a[y][x][k] = 0;
    }

    rep(y,h)rep(x,w)if(s[y][x]=='*'){
        if(IN(y,x-1) && s[y][x-1]=='*') a[y][x][0] = a[y][x-1][0]+1;
        if(IN(y-1,x) && s[y-1][x]=='*') a[y][x][1] = a[y-1][x][1]+1;
    }

    for(int y=h-1; y>=0; --y)for(int x=w-1; x>=0; --x)if(s[y][x]=='*'){
        if(IN(y,x+1) && s[y][x+1]=='*') a[y][x][2] = a[y][x+1][2]+1;
        if(IN(y+1,x) && s[y+1][x]=='*') a[y][x][3] = a[y+1][x][3]+1;
    }

    vector<pi> ans;
    rep(y,h)rep(x,w)if(s[y][x]=='*'){
        int sz = 101010;
        rep(i,4) sz = min(sz, a[y][x][i]);
        if(sz>0){
            ++yy[y-sz][x];
            --yy[y+sz+1][x];
            ++xx[y][x-sz];
            --xx[y][x+sz+1];
            ans.pb({y,x});
        }
    }

    rep(x,w){
        rep(y,h) yy[y+1][x] += yy[y][x];
    }
    rep(y,h){
        rep(x,w) xx[y][x+1] += xx[y][x];
    }

    // check
    bool ok = true;
    rep(y,h)rep(x,w)if(s[y][x]=='*'){
        if(!yy[y][x] && !xx[y][x]) ok = false;
    }

    if(ok){
        cout << ans.size() << endl;
        for(const auto &p:ans){
            int y = p.fi, x = p.se;
            int sz = 101010;
            rep(i,4) sz = min(sz, a[y][x][i]);
            printf("%d %d %d\n", y+1, x+1, sz);
        }
    }
    else cout << -1 << endl;
    return 0;
}
