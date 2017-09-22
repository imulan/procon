#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(int)n; ++i)
#define rrep(i,n) for(int i=(int)n-1; i>=0; --i)
#define inf 1e9


int main()
{
    string s;
    cin >> s;
    int n = s.size();

    set<int> st[26];
    rep(i, n) {
        st[s[i] - 'a'].insert(i);
    }
    rep(c, 26) {
        st[c].insert(-1);
        st[c].insert(inf);
    }

    int q;
    cin >> q;
    rep(k, q) {
        [&](){
            string t;
            cin >> t;
            int m = t.size();

            int r = -1;
            rep(j, m) {
                r = *st[t[j] - 'a'].upper_bound(r);
                if (r == inf) {
                    cout << -1 << endl;
                    return;
                }
            }

            int l = r + 1;
            rrep(j, m) {
                auto itr = st[t[j] - 'a'].lower_bound(l);
                itr--;
                l = *itr;
            }

            cout << l + 1 << " " << r + 1 << endl;
        }();
    }
}
