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

const int A = 26;

void solve(){
    int n,m;
    string s;
    cin >>n >>m >>s;

    vector<vector<int>> add(n);
    vector<int> c(A);
    rep(i,n){
        ++c[s[i]-'a'];
        add[i] = c;
    }

    vector<int> ans = add[n-1];
    rep(i,m){
        int p;
        cin >>p;
        rep(j,A) ans[j] += add[p-1][j];
    }

    rep(i,A) cout << ans[i] << " \n"[i==A-1];
}

int main(){
    int T;
    cin >>T;
    while(T--) solve();
    return 0;
}
