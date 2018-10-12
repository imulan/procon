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

const int mod = 1e9+7;
const int A = 26;
int ct[A];

int main(){
    int n;
    string s,t;
    cin >>n >>s >>t;

    int dp = 1;
    ct[s[0]-'a']++;

    for(int i=1; i<n; ++i){
        dp = ct[t[i]-'a'];
        (ct[s[i]-'a'] += dp) %= mod;
    }

    cout << dp << endl;
    return 0;
}
