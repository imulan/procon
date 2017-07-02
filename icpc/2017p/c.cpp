#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);i++)
#define mp(a,b) make_pair((a),(b))
#define pb(a) push_back((a))
#define all(x) begin(x),end(x)
#define uniq(x) sort(all(x)),(x).erase(unique(all(s)),end(x))
#define dbg(x) cout<<#x" = "<<((x))<<endl
#define fi first
#define se second

using pi = pair<int,int>;

int main() {
    int n,m;
    while(cin >>n >>m, n)
    {
        // input
        vector<int> s(m);
        vector<int> k(m);
        vector<vector<int>> c(m);

        vector<pi> a(n),b(n);
        rep(i,n) a[i]=b[i]=pi(0,i);

        rep(i,m)
        {
            cin >>s[i] >>k[i];
            c[i] = vector<int>(k[i]);
            rep(j,k[i]){
                cin >>c[i][j];
                c[i][j]--;
            }

            if(k[i]==1)
            {
                a[c[i][0]].fi += s[i];
            }
            rep(j,k[i]) b[c[i][j]].fi += s[i];
        }

        sort(all(a));
        // rep(i,n) printf(" a[%d]= %d %d\n", i,a[i].fi,a[i].se);
        // rep(i,n) printf(" b[%d]= %d %d\n", i,b[i].fi,b[i].se);

        int ans = 0;
        rep(i,n)
        {
            if(i==a[0].se) ans = max(ans, b[i].fi-a[1].fi+1);
            else ans = max(ans, b[i].fi-a[0].fi+1);
        }

        cout << ans << endl;

    }
    return 0;
}
