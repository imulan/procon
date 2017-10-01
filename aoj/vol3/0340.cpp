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

    int ans = 19191919;
    rep(i,p[0]+1)
    {
        vector<int> v(p);
        v[0] -= i;
        int t = i;

        for(int j=1; j<n; ++j)
        {
            if(v[j-1]>0)
            {
                t += 2*v[j-1];
                v[j] -= v[j-1];
                v[j-1] = 0;
            }
        }
        if(v[n-1]>0) t += v[n-1];

        ans = min(ans,t);
    }

    cout << ans << endl;
    return 0;
}
