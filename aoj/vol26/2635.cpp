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

bool solve(){
    int n;
    cin >>n;
    vector<ll> x(n),y(n);
    rep(i,n) cin >>x[i] >>y[i];

    rep(i,n-1){
        ll Dx = x[i+1]-x[i], Dy = y[i+1]-y[i];

        ll b = Dx*x[i] + Dy*y[i] - x[i+1]*Dx - y[i+1]*Dy;
        for(int j=i+1; j<n; ++j){
            ll t = Dx*x[j] + Dy*y[j] - x[i+1]*Dx - y[i+1]*Dy;
            if(b<0 && t<0) return false;
            if(b>0 && t>0) return false;
        }
    }

    return true;
}

int main(){
    cout << (solve()?"Possible":"Impossible") << endl;
    return 0;
}
