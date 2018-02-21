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

inline ll f(ll x){
    return x*(x-1)/2;
}

int main(){
    int Q;
    scanf(" %d", &Q);
    while(Q--){
        ll n;
        scanf(" %lld", &n);

        ll l=n-1, r=2*n;
        while(r-l>1){
            ll m = (l+r)/2;
            // 最低限必要な橋の個数
            ll b = (m+1)/2;
            // 残りの辺の数
            ll rem = m-b;

            // 消化しきれるか?
            if(b+1<=n && f(n-b)>=rem) l = m;
            else r = m;
        }
        printf("%lld\n",l);
    }
    return 0;
}
