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

int main(){
    int w,h,n;
    cin >>w >>h >>n;

    vector<int> p(n);
    rep(i,n) cin >>p[i];

    int ux=1, uy=1;
    int udx=1, udy=0;

    int sx=1, sy=2;
    int sdx=1, sdy=0;

    int ans = 0;
    rep(i,n){
        if(p[i]==0){
            ux += udx;
            uy += udy;

            if(ux==w){
                udx = 0;
                udy = 1;
                if(uy==h){
                    udx = -1;
                    udy = 0;
                }
            }
        }
        else{
            sx += sdx;
            sy += sdy;

            if(sx==w-1){
                sdx = 0;
                sdy = 1;
                if(sy==h-1){
                    sdx = -1;
                    sdy = 0;
                }
            }
        }

        if(ux<0 || sx<0) break;
        if(abs(ux-sx)+abs(uy-sy) == 1) ++ans;
    }
    cout << ans << endl;
    return 0;
}
