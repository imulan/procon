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
    string s;
    cin >>s;
    int n = s.size();

    vector<int> v(A);
    for(char c:s) ++v[c-'A'];
    sort(all(v), greater<int>());
    // dbg(v);

    int ans = n;
    for(int i=1; i<=A; ++i){
        if(n%i!=0) continue;

        int t = n/i;
        int c = 0;
        rep(j,i) c += max(0,v[j]-t);
        for(int j=i; j<A; ++j) c += v[j];

        ans = min(ans, c);
    }
    return ans;
}

int main(){
    int T;
    cin >>T;
    rep(_,T) cout << solve() << "\n";
    return 0;
}
