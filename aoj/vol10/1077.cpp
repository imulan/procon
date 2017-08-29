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

int main()
{
    while(1)
    {
        int x[6];
        rep(i,6) cin >>x[i];

        int s = 0;
        rep(i,6) s += x[i];
        if(s==0) break;

        int a = x[0] + x[3];
        int b = x[1] + x[4];
        int c = x[2] + x[5];

        int m = min({a,b,c});

        int ans = 0;
        for(int i=m; i>=max(0,m-3); --i) ans = max(ans, i+(a-i)/3+(b-i)/3+(c-i)/3);
        cout << ans << endl;
    }
    return 0;
}
