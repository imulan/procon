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

ll f(ll n, ll m){
    return n*n - (n/m)*(n/m);
}

const ll INF = 1000000000;

void solve(){
    int x;
    cin >>x;

    if(x==0){
        cout << 1 << " " << 1 << endl;
        return;
    }
    if(x==1){
        cout << -1 << endl;
        return;
    }

    for(int i=1; i*i<=x; ++i)if(x%i==0){
        int j = x/i;
        // printf(" i,j %d %d\n", i,j);

        if((i+j)%2 != 0) continue;

        int n = (i+j)/2;
        // printf(" n = %d\n", n);

        if(j-n<=0 || n<=0) continue;

        int m = n/(j-n);
        // printf(" m = %d\n", m);

        if(m<=0) continue;

        if(f(n,m) == x){
            cout << n << " " << m << endl;
            return;
        }
    }

    cout << -1 << endl;
}

int main(){
    int T;
    cin >>T;
    while(T--) solve();
    return 0;
}
