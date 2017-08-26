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
    string a;
    cin >>a;

    int A = a.size();
    int ct[26]={};
    rep(i,A) ++ct[a[i]-'a'];

    ll ans = 1;
    rep(i,A)
    {
        --ct[a[i]-'a'];
        rep(j,26)if(a[i]-'a'!=j) ans += ct[j];
    }

    cout << ans << endl;
    return 0;
}
