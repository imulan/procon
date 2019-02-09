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

ll solve(){
    ll k,a,b;
    cin >>k >>a >>b;

    if(b <= a) return k+1;

    // b-a > 0

    ll ans = k+1;

    ll rem = k-(a-1);
    if(rem>0){
        ll num = rem/2;

        ll t = num*(b-a);
        if(rem%2==1) ++t;
        // dbg(t);
        ans = max(ans, t+a);
    }
    return ans;
}

int main(){
    cout << solve() << endl;
    return 0;
}
