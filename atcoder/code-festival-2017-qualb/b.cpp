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
    vector<int> d(n);
    rep(i,n) cin >>d[i];

    int m;
    cin >>m;
    vector<int> t(m);
    rep(i,m) cin >>t[i];

    sort(all(d));
    sort(all(t));

    int j=0;
    rep(i,n)
    {
        if(j==m) break;

        if(d[i]==t[j]) ++j;
    }

    string ans = "NO";
    if(j==m) ans="YES";
    cout << ans << endl;
    return 0;
}
