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
const ll INF = LLONG_MAX/3;

int main(){
    int n,D;
    cin >>n >>D;

    map<pi,int> ct;
    rep(i,n){
        int x,y;
        cin >>x >>y;
        x%=D;
        y%=D;
        ++ct[{x,y}];
    }

    if(D>40) assert(false);

    auto check = [&](ll b){
        rep(x,D)rep(y,D){
            bool ok = true;
            rep(i,D)rep(j,D){
                if(!ct.count({i,j})) continue;

                int sx = i;
                if(i<x) sx += D;
                int sy = j;
                if(j<y) sy += D;

                if(x+b-sx>=0 && y+b-sy>=0){
                    ll zx = (x+b-sx)/D;
                    ++zx;
                    ll zy = (y+b-sy)/D;
                    ++zy;

                    ll num = ct[{i,j}];
                    if(zx*zy < num){
                        ok = false;
                        i=j=D;
                    }
                }
                else{
                    ok = false;
                    i=j=D;
                }
            }
            if(ok) return true;
        }
        return false;
    };

    ll ng=0, ok=10000000;
    while(ok-ng>1){
        ll mid = (ng+ok)/2;
        if(check(mid)) ok = mid;
        else ng = mid;
    }
    cout << ok << endl;

    return 0;
}
