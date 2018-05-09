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

int main(){
    int n,w,d;
    cin >>n >>w >>d;

    auto crosspoint = [&](int dx, int dy, pi p){
        int mind = 19191919;
        pi ret(-1,-1);

        int D;
        // x = 0
        D = -p.fi/dx;
        if(D>=0){
            if(D < mind){
                mind = D;
                ret = {0, p.se+D*dy};
            }
        }

        // x = w
        D = (w-p.fi)/dx;
        if(D>=0){
            if(D < mind){
                mind = D;
                ret = {w, p.se+D*dy};
            }
        }

        // y = 0
        D = -p.se/dy;
        if(D>=0){
            if(D < mind){
                mind = D;
                ret = {p.fi+D*dx, 0};
            }
        }

        // y = d
        D = (d-p.se)/dy;
        if(D>=0){
            if(D < mind){
                mind = D;
                ret = {p.fi+D*dx, d};
            }
        }

        assert(ret.fi != -1);
        return ret;
    };

    auto cv = [&](pi p){
        if(p.se == 0) return p.fi;
        if(p.fi == w) return w+p.se;
        if(p.se == d) return w+d+(w-p.fi);
        return w+d+w+(d-p.se);
    };

    vector<pi> r(n);
    rep(i,n){
        int x,y;
        char f;
        cin >>x >>y >>f;

        int rdx,rdy,ldx,ldy;
        if(f=='N'){
            rdx = 1;
            rdy = 1;
            ldx = -1;
            ldy = 1;
        }
        else if(f=='E'){
            rdx = 1;
            rdy = -1;
            ldx = 1;
            ldy = 1;
        }
        else if(f=='W'){
            rdx = -1;
            rdy = 1;
            ldx = -1;
            ldy = -1;
        }
        else if(f=='S'){
            rdx = -1;
            rdy = -1;
            ldx = 1;
            ldy = -1;
        }

        pi s = crosspoint(rdx,rdy,{x,y});
        pi g = crosspoint(ldx,ldy,{x,y});

        r[i] = {cv(s), cv(g)};
    }

    auto include = [&](pi p, int s){
        if(p.fi<p.se) return p.fi<=s && s<=p.se;
        else return p.fi<=s || s<=p.se;
    };

    auto check = [&](int idx){
        int MOD = 2*(d+w);
        int s = r[idx].se;

        using P = pair<int,pi>;
        vector<P> ev;
        rep(i,n){
            if(!include(r[i],s)){
                ev.pb({(r[i].fi-s+MOD)%MOD, {0,i}});
                ev.pb({(r[i].se-s+MOD)%MOD, {1,i}});
            }
        }
        sort(all(ev));

        int ret = 1;
        vector<bool> used(n);
        set<int> in;
        for(const auto &e:ev){
            int act = e.se.fi;
            int ID = e.se.se;

            if(act == 0) in.insert(ID);
            else{
                if(!used[ID]){
                    for(int i:in) used[i] = true;
                    in.clear();
                    ++ret;
                }
            }
        }
        return ret;
    };

    int ans = n;
    rep(i,n) ans = min(ans, check(i));
    cout << ans << endl;
    return 0;
}
