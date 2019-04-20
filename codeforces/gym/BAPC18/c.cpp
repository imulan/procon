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

const ll INF = LLONG_MAX/3;

vector<int> divisor(int n){
    vector<int> ret;
    for(int i=1; i*i<=n; ++i){
        if(n%i==0){
            ret.pb(i);
            if(n/i != i) ret.pb(n/i);
        }
    }

    sort(all(ret));
    return ret;
}

int main(){
    int V;
    cin >>V;

    vector<int> d = divisor(V);

    ll ans = INF;
    for(int a:d){
        int bc = V/a;
        for(int b:divisor(bc)){
            int c = bc/b;

            ll area = (ll)a*b + (ll)b*c + (ll)c*a;
            area *= 2;
            ans = min(ans, area);
        }
    }
    cout << ans << endl;

    return 0;
}
