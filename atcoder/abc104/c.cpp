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
    int d,g;
    cin >>d >>g;
    vector<int> p(d), c(d);
    rep(i,d) cin >>p[i] >>c[i];

    int ans = 1234;
    rep(mask,1<<d){
        int ct = 0;
        int s = 0;

        rep(i,d)if(mask>>i&1){
            ct += p[i];
            s += c[i] + p[i]*100*(i+1);
        }

        if(s>=g) ans = min(ans,ct);
        for(int i=d-1; i>=0; --i)if(!(mask>>i&1)){
            rep(j,p[i]){
                ++ct;
                s += 100*(i+1);
                if(s>=g) ans = min(ans,ct);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
