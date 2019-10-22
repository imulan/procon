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

int main(){
    cin.tie(0);ios::sync_with_stdio(false);

    int n;
    cin >>n;

    ll sa = 0;
    vector<ll> a(n);
    rep(i,n){
        cin >>a[i];
        sa += a[i];
    }
    sort(all(a), greater<ll>());

    int m;
    cin >>m;
    while(m--){
        int q;
        cin >>q;
        cout << sa-a[q-1] << "\n";
    }
    return 0;
}
