#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);i++)

int main() {
    int n,m;
    while(cin >>n >>m,n)
    {
        vector<int> mv(m+1);
        rep(i,n)
        {
            int d,v;
            cin >>d >>v;
            mv[d] = max(mv[d],v);
        }

        int ans = 0;
        rep(i,m+1) ans += mv[i];
        cout << ans << endl;
    }
    return 0;
}
