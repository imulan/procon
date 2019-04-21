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
    int n,k;
    cin >>n >>k;
    vector<int> a(n);
    rep(i,n) cin >>a[i];

    vector<int> g(k+1);
    rep(x,k+1){
        set<int> s;
        rep(i,n)if(x-a[i] >= 0) s.insert(g[x-a[i]]);

        int r = 0;
        while(s.count(r)) ++r;
        g[x] = r;
    }

    string ans = "Second";
    if(g[k] != 0) ans = "First";
    cout << ans << "\n";
    return 0;
}
