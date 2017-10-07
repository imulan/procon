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
    int n;
    cin >>n;
    vector<int> p(n);
    rep(i,n) cin >>p[i];

    int ans = 0;
    while(1)
    {
        int ct = 0;
        rep(i,n) ct += (p[i]>=ans+1);

        if(ct>=ans+1) ++ans;
        else break;
    }
    cout << ans << endl;
    return 0;
}
