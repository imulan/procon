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
    ll n,k,s;
    cin >>n >>k >>s;

    if(s<k || k*(n-1)<s){
        cout << "NO" << endl;
        return 0;
    }

    vector<ll> h(k);

    ll d = s/k;
    vector<ll> mv(k,d);
    rep(i,s%k) ++mv[i];

    ll now = 1;
    rep(i,k){
        if(i%2==0) now += mv[i];
        else now -= mv[i];
        h[i] = now;
    }

    cout << "YES" << endl;
    rep(i,k) cout << h[i] << " \n"[i==k-1];
    return 0;
}
