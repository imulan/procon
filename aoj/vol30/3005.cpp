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

const int dx[8]={1,1,0,-1,-1,-1,0,1};
const int dy[8]={0,-1,-1,-1,0,1,1,1};

using pi = pair<int,int>;

int solve(){
    int w,h,k;
    cin >>w >>h >>k;

    vector<pi> p(k);
    map<pi,int> m;
    rep(i,k){
        int x,y;
        scanf(" %d %d", &x, &y);
        p[i] = {y,x};
        m[p[i]] = i;
    }

    auto IN = [&](int y, int x){
        return 0<=y && y<h && 0<=x && x<w;
    };

    auto isS = [&](pi t){
        if(t.fi == h-1) return t.se != w-1;
        if(t.se == 0) return t.fi != 0;
        return false;
    };

    auto isT = [&](pi t){
        if(t.fi == 0) return t.se != 0;
        if(t.se == w-1) return t.fi != h-1;
        return false;
    };

    queue<int> que;

    vector<bool> viss(k);
    rep(i,k){
        if(isS(p[i])){
            viss[i] = true;
            que.push(i);
        }
    }
    while(!que.empty()){
        int now = que.front();
        que.pop();
        rep(i,8){
            int ny = p[now].fi+dy[i], nx = p[now].se+dx[i];
            if(!IN(ny,nx)) continue;

            if(m.count({ny,nx})){
                int idx = m[{ny,nx}];
                if(!viss[idx]){
                    viss[idx] = true;
                    que.push(idx);
                }
            }
        }
    }

    vector<bool> vist(k);
    rep(i,k){
        if(isT(p[i])){
            vist[i] = true;
            que.push(i);
        }
    }
    while(!que.empty()){
        int now = que.front();
        que.pop();
        rep(i,8){
            int ny = p[now].fi+dy[i], nx = p[now].se+dx[i];
            if(!IN(ny,nx)) continue;

            if(m.count({ny,nx})){
                int idx = m[{ny,nx}];
                if(!vist[idx]){
                    vist[idx] = true;
                    que.push(idx);
                }
            }
        }
    }

    rep(i,k)if(viss[i] && vist[i]) return 0;

    rep(i,k)rep(j,8){
        int ny = p[i].fi+dy[j], nx = p[i].se+dx[j];
        if(!IN(ny,nx)) continue;

        bool ss = false, tt = false;
        rep(d,8){
            int Y = ny+dy[d], X = nx+dx[d];
            if(!IN(Y,X)) continue;
            if(m.count({Y,X})){
                int idx = m[{Y,X}];
                if(viss[idx]) ss = true;
                if(vist[idx]) tt = true;
            }
        }
        if(ss && tt) return 1;

        if(viss[i] && isT({ny,nx})) return 1;
        if(vist[i] && isS({ny,nx})) return 1;
    }

    return 2;
}

int main(){
    cout << solve() << endl;
    return 0;
}
