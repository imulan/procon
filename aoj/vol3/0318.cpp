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
    rep(i,3)
    {
        int m;
        cin >>m;
        while(m--)
        {
            int x;
            cin >>x;
            p[x-1] |= 1<<i;
        }
    }

    int ans = 0;
    rep(i,n) ans += (p[i]==4 || p[i]==6 || p[i]==7);
    cout << ans << endl;
    return 0;
}
