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

const int N = 1000010;
bool NG[N];
int ct[N];

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) {
        cin >> a[i];
        ++ct[a[i]];
    }
    sort(all(a));

    int ans = 0;
    for (int i : a) {
        if (NG[i]) continue;
        if (ct[i] < 2) ++ans;
        for (int j = i; j < N; j += i) NG[j] = true;
    }
    cout << ans << "\n";
    return 0;
}
