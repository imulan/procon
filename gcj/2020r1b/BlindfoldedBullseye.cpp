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

const ll INF = 1000000000;

ll A,B;

inline int ASK(ll x, ll y){
    cout << x << " " << y << endl;

    string s;
    cin >>s;
    if(s == "CENTER") return 0;
    else if(s == "HIT") return 1;
    else return -1;
}

void solve_vis(){
    // X-axis
    ll llx = -INF, lrx = 0;
    while(lrx - llx > 1){
        ll mid = (llx+lrx)/2;
        int res = ASK(mid, 0);
        if(res == 0) return;

        if(res == 1) lrx = mid;
        else llx = mid;
    }

    ll rlx = 0, rrx = INF;
    while(rrx - rlx > 1){
        ll mid = (rlx+rrx)/2;
        int res = ASK(mid, 0);
        if(res == 0) return;

        if(res == 1) rlx = mid;
        else rrx = mid;
    }

    ll cx = (lrx+rlx)/2;

    // Y-axis
    ll lly = -INF, lry = 0;
    while(lry - lly > 1){
        ll mid = (lly+lry)/2;
        int res = ASK(0,mid);
        if(res == 0) return;

        if(res == 1) lry = mid;
        else lly = mid;
    }

    ll rly = 0, rry = INF;
    while(rry - rly > 1){
        ll mid = (rly+rry)/2;
        int res = ASK(0,mid);
        if(res == 0) return;

        if(res == 1) rly = mid;
        else rry = mid;
    }

    ll cy = (lry+rly)/2;

    for(int i=-5; i<=5; ++i)for(int j=-5; j<=5; ++j){
        int res = ASK(cx+i, cy+j);
        if(res == 0) return;
    }


}

ll FIND(ll pos, ll fix, ll m, char XY){
    ll ok=0, ng=2*INF+1;
    while(ng-ok>1){
        ll mid = (ok+ng)/2;
        ll tp = pos + m*mid;

        if(tp<-INF || INF<tp){
            ng = mid;
            continue;
        }

        int res;
        if(XY == 'X') res = ASK(tp, fix);
        else res = ASK(fix, tp);

        if(res == 0) return -1;

        if(res == 1) ok = mid;
        else ng = mid;
    }
    // cerr << "OK " << ok << endl;

    return pos + m*ok;
}

void solve(){
    bool found_candidate = false;
    ll cx, cy;
    for(int i:{1,2})for(int j:{1,2}){
        ll x = -INF + i*2*INF/3;
        ll y = -INF + j*2*INF/3;

        int res = ASK(x,y);
        if(res == 0) return;

        if(res == 1){
            found_candidate = true;
            cx = x;
            cy = y;
            break;
        }
    }
    if(!found_candidate) assert(false);

    cerr << cx << " " << cy << endl;

    ll lx = FIND(cx,cy,-1,'X');
    if(lx == -1) return;
    ll rx = FIND(cx,cy,1,'X');
    if(rx == -1) return;
    ll ly = FIND(cy,cx,-1,'Y');
    if(ly == -1) return;
    ll ry = FIND(cy,cx,1,'Y');
    if(ry == -1) return;


    ll mx = (lx+rx)/2, my = (ly+ry)/2;
    // cerr << " X? " <<lx << " " << rx << endl;
    // cerr << " Y? " <<ly << " " << ry << endl;
    // cerr << "MM" <<mx << " " << my << endl;

    for(int i=-5; i<=5; ++i)for(int j=-5; j<=5; ++j){
        int res = ASK(mx+i, my+j);
        if(res == 0) return;
    }
}

int main(){
    int T;
    cin >>T >>A >>B;
    rep(i,T){
        // solve_vis();
        solve();
    }
    return 0;
}
