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

string solve(){
    vector<int> x(4);
    rep(i,4) cin >>x[i];
    sort(all(x));

    string ans = "YES";
    rep(i,2)if(x[2*i]!=x[2*i+1]) ans = "NO";
    return ans;
}

int main(){
    int T;
    cin >>T;
    while(T--) cout << solve() << endl;
    return 0;
}
