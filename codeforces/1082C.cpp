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
    int n;
    string s;
    cin >>n >>s;

    vector<int> r(n);
    int st = 0;
    int g = 0, ctr = 0;
    while(st<n){
        if(s[st]=='G'){
            ++ctr;
            int nx = st;
            while(nx<n && s[nx]=='G') ++nx;

            for(int i=st; i<nx; ++i) r[i] = nx-st;
            g += nx-st;
            st = nx;
        }
        else ++st;
    }

    int ans = 0;
    rep(i,n) ans = max(ans,r[i]);
    if(ctr >= 2) ++ans;

    for(int i=1; i<n-1; ++i){
        if(s[i]=='S'){
            int t = r[i-1]+r[i+1];
            ans = max(ans, min(g,t+1));
        }
    }

    cout << ans << "\n";
    return 0;
}
