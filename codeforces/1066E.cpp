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

const ll mod = 998244353;

const int N = 200002;
ll pw[N];

int main(){
    pw[0] = 1;
    for(int i=1; i<N; ++i) pw[i] = (pw[i-1]*2)%mod;

    int A,B;
    string a,b;
    cin >>A >>B >>a >>b;

    reverse(all(a));
    reverse(all(b));

    set<int> s;
    rep(i,B)if(b[i]=='1') s.insert(i);

    ll ans = 0;
    rep(i,A){
        if(a[i]=='1'){
            ll sz = s.size();
            (ans += pw[i]*sz) %= mod;
        }

        if(*s.begin() == i){
            s.erase(s.begin());
        }
    }
    cout << ans << endl;
    return 0;
}
