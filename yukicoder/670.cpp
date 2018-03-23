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

using ull = unsigned long long;

ull seed;
int next() {
    seed = seed ^ (seed << 13);
    seed = seed ^ (seed >> 7);
    seed = seed ^ (seed << 17);
    return (seed >> 33);
}

const int B = 1<<18;
const int SZ = 1<<13;

vector<int> v[B];
int sum[B];

int main(){
    int n, q;
    cin >>n >> q >> seed;
    for (int i = 0; i < 10000; i++) next();

    vector<int> a(n);
    for (int i = 0; i < n; i++){
        a[i] = next();

        int bid = a[i]/SZ;
        v[bid].pb(a[i]);
        ++sum[bid];
    }

    rep(i,B-1) sum[i+1] += sum[i];

    ll sm = 0;
    for (int i = 0; i < q; i++) {
        int x = next();
        int bid = x/SZ;

        int cnt = 0;
        if(bid>0) cnt = sum[bid-1];
        for(int j:v[bid]) cnt += (j<x);
        sm ^= ll(cnt) * i;
    }
    cout << sm << endl;
    return 0;
}
