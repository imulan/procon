#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

const int dx[4]={1,-1,0,0};
const int dy[4]={0,0,1,-1};

bool solve(){
    int h,w;
    cin >>h >>w;
    vector<string> s(h);
    rep(i,h) cin >>s[i];

    auto IN = [&](int y, int x){
        return 0<=y && y<h && 0<=x && x<w;
    };

    rep(y,h)rep(x,w)if(s[y][x]=='*'){
        bool base = true;
        rep(i,4){
            int ny = y+dy[i], nx = x+dx[i];
            base &= (IN(ny,nx) && s[ny][nx]=='*');
        }
        if(!base) continue;

        rep(i,4){
            int cy = y+dy[i], cx = x+dx[i];
            while(IN(cy,cx) && s[cy][cx]=='*'){
                s[cy][cx] = '.';
                cy += dy[i];
                cx += dx[i];
            }
        }
        s[y][x] = '.';

        rep(i,h)rep(j,w)if(s[i][j]=='*') return false;
        return true;
    }

    return false;
}

int main(){
    cout << (solve()?"YES":"NO") << "\n";
    return 0;
}
