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

inline int SQ(int x){ return x*x; }

int f(int x, int k)
{
    int ans = 0;
    rep(i,x/k)rep(j,x/k)
    {
        int t = 1;
        rep(ii,2)rep(jj,2)
        {
            int X = k*(i+ii), Y = k*(j+jj);
            int d2 = SQ(x/2-X)+SQ(x/2-Y);
            if(d2>SQ(x/2)) t = 0;
        }
        ans += t;
    }
    return ans;
}

int main()
{
    int k;
    cin >>k;
    cout << f(200,k) << " " << f(300,k) << endl;
    return 0;
}
