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
    string s,t;
    cin >>s >>t;
    int S = s.size(), T = t.size();

    vector<int> pre(T),suf(T);

    int tidx = 0;
    rep(i,S){
        if(tidx<T && s[i]==t[tidx]){
            pre[tidx] = i;
            ++tidx;
        }
    }

    tidx = T-1;
    for(int i=S-1; i>=0; --i){
        if(tidx>=0 && s[i]==t[tidx]){
            suf[tidx] = i;
            --tidx;
        }
    }

    int ans = 0;
    rep(i,T-1) ans = max(ans, suf[i+1]-pre[i]-1);
    ans = max(ans, S-1-pre[T-1]);
    ans = max(ans, suf[0]);

    cout << ans << "\n";
    return 0;
}
