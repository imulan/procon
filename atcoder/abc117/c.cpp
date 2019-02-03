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
    vector<int> x(m);
    rep(i,m) cin >>x[i];

    sort(all(x));

    if(n>=m){
        cout << 0 << endl;
        return 0;
    }

    vector<int> d;
    rep(i,m-1) d.pb(x[i+1]-x[i]);
    sort(all(d), greater<int>());

    int s = 0;
    for(int i:d) s += i;
    rep(i,n-1) s -= d[i];

    cout << s << endl;
    return 0;
}
