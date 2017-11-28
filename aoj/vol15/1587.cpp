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

int f[50][50];
int main()
{
    int W,H,T,p;
    cin >>W >>H >>T >>p;

    vector<int> x(p),y(p),t(p);
    rep(i,p) cin >>x[i] >>y[i] >>t[i];

    rep(i,H)rep(j,W)
    {
        cin >>f[i][j];
        --f[i][j];
    }

    rep(i,p)if(f[y[i]][x[i]]!=-1) ++f[y[i]][x[i]];

    int ans = 0;
    rep(i,H)rep(j,W)if(f[i][j]!=-1) ans += f[i][j];
    cout << ans << endl;
    return 0;
}
