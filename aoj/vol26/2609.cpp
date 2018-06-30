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

const int N = 1000100;


int main(){
    ll w,h,v,t,x,y,p,q;
    cin >>w >>h >>v >>t >>x >>y >>p >>q;

    ll r = v*t;

    ll y1 = q, y2 = h+(h-q);
    vector<ll> yy;
    for(int i=-N/2; i<=N/2; ++i){
        yy.pb(y1+h*i*2);
        yy.pb(y2+h*i*2);
    }
    sort(all(yy));

    ll ans = 0;
    for(int i=-N; i<=N; ++i){
        ll X = w*i;
        if(i%2==0) X+=p;
        else X+=w-p;

        if(abs(X-x) > r) continue;

        ll D = r*r - (X-x)*(X-x);
        if(D<0) continue;

        ll ly = y-(ll)sqrt(D);
        ll ry = y+(ll)sqrt(D);

        int lidx = lower_bound(all(yy), ly) - yy.begin();
        int ridx = upper_bound(all(yy), ry) - yy.begin();
        ans += ridx-lidx;

        // printf(" %d: [%d] %d ~ [%d] %d\n",i,lidx,yy[lidx],ridx,yy[ridx]);
    }
    cout << ans << endl;
    return 0;
}
