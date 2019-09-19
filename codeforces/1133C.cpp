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
    cin >>n;

    map<int,int> ct;
    rep(i,n){
        int a;
        cin >>a;
        ++ct[a];
    }

    int ans = 1;
    for(const auto &p:ct){
        int t = 0;
        rep(i,6){
            int v = p.fi+i;
            if(ct.count(v)) t += ct[v];
        }
        ans = max(ans, t);
    }
    cout << ans << "\n";
    return 0;
}
