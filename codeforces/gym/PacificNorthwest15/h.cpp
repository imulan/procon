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

double s;

vector<pi> F(const vector<pi> &v, int st, int cw, int d, double lx, double ly){
    if(v.size()<=1) return v;

    double w = s/(1<<d);
    double rx = lx+w, ry = ly+w;
    double mx = lx+w/2, my = ly+w/2;

    vector<pi> c[4];
    for(pi p:v){
        int x = p.fi, y = p.se;

        int cid;
        if(x < mx){
            if(y < my) cid = 2;
            else cid = 1;
        }
        else{
            if(y < my) cid = 3;
            else cid = 0;
        }

        c[cid].pb(p);
    }

    vector<int> ord;

    int add = -1;
    if(cw) add = 1;

    int idx = st;
    rep(i,4){
        ord.pb(idx);
        idx = (idx+4+add)%4;
    }

    vector<pi> ret;
    rep(i,4){
        int nst = st;
        if(i == 3) nst = (st+2)%4;

        int ncw = cw;
        if(i==0 || i==3) ncw = !cw;

        double LX = lx, LY = ly;
        if(ord[i] == 1) LY = my;
        else if(ord[i] == 3) LX = mx;
        else if(ord[i] == 0){
            LX = mx;
            LY = my;
        }

        for(pi p:F(c[ord[i]], nst, ncw, d+1, LX, LY)) ret.pb(p);
    }
    return ret;
}

int main(){
    int n;
    cin >>n >>s;

    map<pi,string> p2id;
    vector<pi> v(n);
    rep(i,n){
        int x,y;
        string name;
        cin >>x >>y >>name;

        v[i] = {x,y};
        p2id[v[i]] = name;
    }

    vector<pi> ans = F(v,2,0,0,0,0);
    for(pi p:ans) cout << p2id[p] << "\n";
    return 0;
}
