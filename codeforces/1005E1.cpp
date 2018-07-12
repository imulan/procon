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
    int n,m;
    cin >>n >>m;

    vector<int> p(n);
    rep(i,n) cin >>p[i];

    int ct = 0;
    int idx = -1;
    vector<int> v(n);
    map<int,int> x;
    rep(i,n){
        if(p[i]==m) idx = i;
        else if(p[i]<m) --ct;
        else ++ct;

        v[i] = ct;
        if(idx!=-1) ++x[ct];
    }

    ct = 0;

    ll ans = 0;
    rep(i,idx+1){
        if(x.count(0+ct)) ans += x[0+ct];
        if(x.count(1+ct)) ans += x[1+ct];

        if(p[i]==m) idx = i;
        else if(p[i]<m) --ct;
        else ++ct;
    }
    cout << ans << endl;
    return 0;
}
