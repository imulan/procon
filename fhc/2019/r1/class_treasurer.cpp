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

const ll mod = 1e9+7;
const int N = 1000010;
ll pw[N];

ll solve(){
    int n,k;
    string s;
    cin >>n >>k >>s;

    ll ret = 0;

    stack<int> st;
    int ct = 0;
    for(int i=n-1; i>=0; --i){
        if(s[i]=='A') ++ct;
        else{
            --ct;
            st.push(i);
        }

        if(ct < -k){
            int idx = st.top();
            st.pop();
            (ret += pw[idx+1]) %= mod;
            ct += 2;
        }

        if(ct>0){
            ct = 0;
            while(!st.empty()) st.pop();
        }
    }
    return ret;
}

int main(){
    pw[0] = 1;
    for(int i=1; i<N; ++i) pw[i] = (pw[i-1]*2)%mod;


    int T;
    cin >>T;
    rep(i,T) printf("Case #%d: %lld\n", i+1, solve());
    return 0;
}
