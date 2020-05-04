// clang-format off
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
// clang-format on

string f(string s, int mask) {
    int n = s.size();
    rep(i, n) if (mask >> i & 1) s[i] = '.';
    return s;
}

int main() {
    string s;
    cin >> s;
    int n = s.size();

    set<string> a;
    rep(i, n) {
        rep(j, 3) if (i + j < n) {
            int L = j + 1;
            string t = s.substr(i, L);
            rep(mask, 1 << L) a.insert(f(t, mask));
        }
    }
    cout << a.size() << "\n";
    return 0;
}
