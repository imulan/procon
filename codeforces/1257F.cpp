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

const int N = 15;
const int BIT_MASK = (1<<N)-1;

int solve(){
    int n;
    cin >>n;
    vector<int> a(n);
    rep(i,n) cin >>a[i];

    map<vector<int>, int> low;
    rep(mask,1<<N){
        vector<int> v(n);
        rep(i,n){
            int t = a[i]&BIT_MASK;
            t ^= mask;
            v[i] = __builtin_popcount(t);
        }

        for(int i=1; i<n; ++i) v[i] -= v[0];
        v[0] = 0;

        low[v] = mask;
    }

    rep(mask,1<<N){
        vector<int> v(n);
        rep(i,n){
            int t = a[i]>>N;
            t &= BIT_MASK;
            t ^= mask;
            v[i] = __builtin_popcount(t);
        }

        for(int i=1; i<n; ++i) v[i] -= v[0];
        v[0] = 0;

        rep(i,n) v[i] = -v[i];

        if(low.count(v)) return (mask<<N)|low[v];
    }

    return -1;
}

int main(){
    cout << solve() << "\n";
    return 0;
}
