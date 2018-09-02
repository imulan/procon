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
    ll n;
    int Q;
    scanf(" %lld %d", &n, &Q);
    while(Q--){
        int x,y;
        scanf(" %d %d", &x, &y);
        --x;
        --y;

        ll ans = 0;
        int oe = (x+y)%2;

        if(oe==1) ans += (n*n+1)/2;

        ans += n*(x/2);
        if(x%2==1) ans += n/2+(!oe & n%2);
        ans += y/2;

        printf("%lld\n", ans+1);
    }
    return 0;
}
