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
    int h,w;
    cin >>h >>w;
    vector<string> a(h);
    rep(i,h) cin >>a[i];

    int ct = 0;
    rep(i,h)rep(j,w) ct += (a[i][j]=='#');

    cout << (ct==h+w-1?"Possible":"Impossible") << endl;

    return 0;
}
