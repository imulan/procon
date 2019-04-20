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

const int A = 26;

int solve(){
    int n;
    cin >>n;

    vector<vector<bool>> a(n);
    rep(i,n){
        string s;
        cin >>s;

        vector<bool> e(A);
        for(char c:s) e[c-'a'] = true;
        a[i] = e;
    }

    int ans = 0;
    rep(i,A){
        int add = 1;
        rep(j,n)if(!a[j][i]) add = 0;
        ans += add;
    }
    return ans;
}

int main(){
    int T;
    cin >>T;
    rep(_,T) cout << solve() << "\n";
    return 0;
}
