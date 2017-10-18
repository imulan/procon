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
    vector<int> a(n);
    rep(i,n) cin >>a[i];

    int ans = 1;

    int st = 0;
    rep(i,n)
    {
        if(i==n-1 || a[i]>a[i+1])
        {
            ans = max(ans,i-st+1);
            st = i+1;
        }
    }

    st = 0;
    rep(i,n)
    {
        if(i==n-1 || a[i]<a[i+1])
        {
            ans = max(ans,i-st+1);
            st = i+1;
        }
    }

    cout << ans << endl;
    return 0;
}
