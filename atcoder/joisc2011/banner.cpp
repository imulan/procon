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

int h,w;
int f[400][400];

int main()
{
    cin >>h >>w;
    rep(i,h)rep(j,w) cin >>f[i][j];

    ll ans = 0;
    rep(i,w)for(int j=i+1; j<w; ++j)
    {
        int ct[8]={};
        for(int k=1; k<h; ++k)
        {
            int v = (1<<f[k][i])|(1<<f[k][j]);
            ++ct[v];
        }

        rep(k,h)
        {
            int v = (1<<f[k][i])|(1<<f[k][j]);
            rep(l,8)if((l|v)==7) ans += ct[l];

            if(k<h-1)
            {
                v = (1<<f[k+1][i])|(1<<f[k+1][j]);
                --ct[v];
            }
        }
    }

    cout << ans << endl;
    return 0;
}
