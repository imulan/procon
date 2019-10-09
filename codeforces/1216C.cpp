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

int main(){
    vector<int> ux,uy;
    int wx[2], wy[2];
    rep(i,2){
        cin >>wx[i] >>wy[i];
        ux.pb(wx[i]);
        uy.pb(wy[i]);
    }

    int bx[2][2], by[2][2];
    rep(i,2)rep(j,2){
        cin >>bx[i][j] >>by[i][j];
        ux.pb(bx[i][j]);
        uy.pb(by[i][j]);
    }

    sort(all(ux));
    ux.erase(unique(all(ux)), ux.end());
    sort(all(uy));
    uy.erase(unique(all(uy)), uy.end());
    int X = ux.size(), Y = uy.size();

    string ans = "NO";
    rep(xx,X-1)rep(yy,Y-1){
        double cx = (ux[xx]+ux[xx+1])*0.5;
        double cy = (uy[yy]+uy[yy+1])*0.5;
        if(wx[0]<cx && cx<wx[1] && wy[0]<cy && cy<wy[1]){
            bool ok = true;
            rep(i,2)if(bx[i][0]<cx && cx<bx[i][1] && by[i][0]<cy && cy<by[i][1]) ok = false;
            if(ok) ans = "YES";
        }
    }
    cout << ans << "\n";
    return 0;
}
