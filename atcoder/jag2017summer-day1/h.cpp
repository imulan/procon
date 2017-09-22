#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(int)n; ++i)
using ll = long long;

int main()
{
    ll x, y;
    cin >> x >> y;
    ll sm = 0ll;
    ll naname = min(abs(x), abs(y));
    // cerr << "naname = " << naname << endl;
    bool f0 = false;
    bool f1 = false;
    bool f2 = false;
    bool f3 = false;

    if (x > 0 && y > 0) {
        sm += 2 * naname;
        f0 = true;
    }
    else if (x < 0 && y > 0) {
        sm += 3 + 6 * (naname - 1);
        f1 = true;
    }
    else if (x < 0 && y < 0) {
        sm += 1 + 4 * (naname - 1);
        f2 = true;
    }
    else if (x > 0 && y < 0) {
        sm += 3 + 6 * (naname - 1);
        f3 = true;
    }

    x = (x > 0 ? +1 : -1) * (abs(x) - naname);
    y = (y > 0 ? +1 : -1) * (abs(y) - naname);
    // cerr << "x = " << x << ", y = " << y << ", sm = " << sm << endl;

    if (x > 0 && y == 0) {
        if (f3) {
            sm += 4 * abs(x);
        }
        else {
            sm += 1 + 4 * (abs(x) - 1);
        }
    }
    else if (x == 0 && y > 0) {
        if (f1) {
            sm += 4 * abs(y);
        }
        else {
            sm += 1 + 4 * (abs(y) - 1);
        }
    }
    else if (x < 0 && y == 0) {
        sm += 2 * abs(x);
    }
    else if (x == 0 && y < 0) {
        sm += 2 * abs(y);
    }

    cout << sm << endl;

}
