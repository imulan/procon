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
    vector<string> s(h);
    rep(i,h) cin >>s[i];

    vector<string> a(h+2,string(w+2,'#'));
    rep(i,h)rep(j,w) a[i+1][j+1] = s[i][j];

    rep(i,h+2) cout << a[i] << endl;
    return 0;
}
