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

using pl = pair<ll,ll>;
using P = pair<pl,int>;

bool cmp(const P &L, const P &R){
    pl lh = L.fi, rh = R.fi;
    return lh.fi*rh.se > rh.fi*lh.se;
}

int main(){
    int n;
    cin >>n;
    vector<string> t(n);
    rep(i,n) cin >>t[i];

    vector<P> v(n);
    rep(i,n){
        int s=0, h=0;
        for(char c:t[i]){
            if(c=='s') ++s;
            else ++h;
        }
        v[i] = {{s,h},i};
    }
    sort(all(v), cmp);

    string c = "";
    rep(i,n) c += t[v[i].se];

    int s=0;
    ll ans=0;
    for(char x:c){
        if(x=='s') ++s;
        else ans += s;
    }
    cout << ans << endl;
    return 0;
}
