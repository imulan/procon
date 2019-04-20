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

ll ask(ll x, ll y){
    cout << "Q";
    for(int v:{x,y}) cout << " " << v;
    cout << endl;

    ll ret;
    cin >>ret;
    return ret;
}

int ans(ll lx, ll ly, ll rx, ll ry){
    cout << "A";
    for(ll v:{lx,ly,rx,ry}) cout << " " << v;
    cout << endl;

    int ret;
    cin >>ret;
    return ret;
}

const ll M = 1e9;

int main(){
    int T;
    cin >>T;
    rep(_,T){
        ll lx,ly,rx,ry;

        ll d_00 = ask(0,0);
        if(d_00 < 0) return 0;
        ll d_M0 = ask(M,0);
        if(d_M0 < 0) return 0;

        ll qx;
        if(d_00 + d_M0 <= M){
            qx = d_00;
        }
        else{
            qx = d_00 - (d_00+d_M0-M)/2;
        }

        ll d_q0 = ask(qx,0);
        if(d_q0 < 0) return 0;

        ly = d_q0;
        lx = d_00 - ly;
        rx = ly + M - d_M0;

        ll d_0M = ask(0,M);
        if(d_0M < 0) return 0;

        ry = lx + M - d_0M;

        if(ans(lx,ly,rx,ry) != 1) return 0;
    }
    return 0;
}
