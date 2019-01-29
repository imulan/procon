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

const ll mod = 100000007;

const int N = 100010;
ll x[N], y[N];

int main(){
    x[0] = 1;
    rep(i,N){
        for(int j=1; j<=5; ++j)if(i+j<N) (x[i+j] += x[i]) %= mod;
        if(i-5>0) (x[i] += x[i-5]) %= mod;
    }
    y[0] = 1;
    rep(i,N){
        for(int j=1; j<=3; ++j)if(i+j<N) (y[i+j] += y[i]) %= mod;
        if(i-3>0) (y[i] += y[i-3]) %= mod;
    }

    string s;
    while(cin >>s,(s!="#")){
        int n = s.size();

        ll ans = 1;
        int i = 0;
        while(i<n){
            int nx = i;
            while(nx<n && s[nx]==s[i]) ++nx;

            int w = nx-i;
            if(s[i]=='8' || s[i]=='0') (ans *= y[w]) %= mod;
            else (ans *= x[w]) %= mod;

            i = nx;
        }

        cout << ans << "\n";
    }
    return 0;
}
