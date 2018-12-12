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

int solve(){
    int n,k;
    cin >>n >>k;

    map<int,int> m;
    rep(i,n){
        int a;
        cin >>a;
        ++m[a];
    }

    vector<int> v;
    for(const auto &p:m) v.pb(p.se);
    sort(all(v), greater<int>());

    if(v.size()<=k) return 0;
    int s = 0;
    rep(i,k) s += v[i];
    return n-s;
}

int main(){
    cout << solve() << endl;
    return 0;
}
