#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

const int MOD = 2019;

int main(){
    string s;
    cin >>s;
    int n = s.size();

    ll ans = 0;
    vector<int> ct(MOD);
    for(const char &c:s){
        int v = c-'0';

        vector<int> nx(MOD);
        rep(i,MOD) nx[(i*10+v)%MOD] += ct[i];
        ++nx[v];

        swap(ct,nx);
        ans += ct[0];
    }

    cout << ans << "\n";
    return 0;
}
