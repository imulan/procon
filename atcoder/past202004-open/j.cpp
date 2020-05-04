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

using pi = pair<int, int>;

string s;

string dfs(int l, int r) {
    if (r - l < 0) return "";
    if (s[l] == '(') {
        int d = 1;
        int i = l + 1;
        while (1) {
            if (s[i] == '(') ++d;
            if (s[i] == ')') --d;
            if (d == 0) break;
            ++i;
        }

        string a = dfs(l + 1, i - 1);
        string ra = a;
        reverse(all(ra));
        return a + ra + dfs(i + 1, r);
    }
    return s[l] + dfs(l + 1, r);
}

int main() {
    cin >> s;
    int n = s.size();
    cout << dfs(0, n - 1) << "\n";
    return 0;
}
