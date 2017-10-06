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

using pi = pair<int,int>;
using P = pair<pi,char>;

int main()
{
    vector<P> v(3);
    rep(i,3)
    {
        int h,w;
        cin >>h >>w;
        v[i].fi = {h,-w};
        v[i].se = 'A'+i;
    }
    sort(all(v));
    reverse(all(v));

    for(const auto &p:v) cout << p.se << endl;
    return 0;
}
