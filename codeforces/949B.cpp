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

void test(ll n){
    vector<int> x(2*n);

    for(int i=1; i<=n; ++i) x[2*i-1] = i;

    while(1){
        int idx = 2*n-1;
        while(x[idx]==0) --idx;
        if(idx == n) break;

        int nx = idx;
        while(x[nx]!=0) --nx;
        x[nx] = x[idx];
        x[idx] = 0;
    }

    for(int i=1; i<=n; ++i) printf(" %d", x[i]);
    puts("");
}

ll query(ll n, ll x){
    if(x%2==1) return (x+1)/2;

    ll pw = 1;
    rep(i,62){
        ll p = x - 2*n + pw;
        ll q = pw*2;
        if(p%q==0){
            ll z = p/q;
            ll ans = n + z;
            if(1<=ans && ans<=n) return ans;
        }

        pw = q;
    }
    assert(false);
}

int main(){
    ll n;
    cin >>n;

    // test(n);
    int q;
    cin >>q;
    while(q--){
        ll x;
        cin >>x;
        cout << query(n,x) << endl;
    }
    return 0;
}
