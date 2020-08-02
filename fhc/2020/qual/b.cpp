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

bool solve() {
    int n;
    string s;
    cin >> n >> s;

    int a = 0, b = 0;
    for (char c : s) {
        if (c == 'A')
            ++a;
        else
            ++b;
    }

    return abs(a - b) == 1;
}

int main() {
    int T;
    cin >> T;
    rep(i, T) printf("Case #%d: %c\n", i + 1, solve() ? 'Y' : 'N');
    return 0;
}
