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

int solve(){
    int c[4];
    rep(i,4) cin >>c[i];

    if(c[0]!=c[3]) return 0;
    if(c[2]>0 && c[0]==0) return 0;
    return 1;
}

int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    cout << solve() << "\n";
    return 0;
}
