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

bool can_make(ll n, int num){
    string s="";
    while(num--) s+='9';
    ll x = atoll(s.c_str());

    ll rem = x-n;
    return rem<n;
}

ll solve(){
    ll n;
    cin >>n;

    int d=0;
    while(can_make(n,d+1)) ++d;

    if(d==0) return n*(n-1)/2;

    string s="";
    rep(_,d) s+='9';

    ll ret = 0;
    rep(i,9){
        string t = string(1,('0'+i))+s;
        ll x = atoll(t.c_str());
        if(x/2+1 > n) continue;

        ll u = x/2;
        ll l = max(1LL,x-n);
        ret += u-l+1;
    }
    return ret;
}

int main(){
    cout << solve() << endl;
    return 0;
}
