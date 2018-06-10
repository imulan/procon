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
using P = pair<pi,pi>;

int main(){
    int n;
    cin >>n;

    vector<int> a(n),d(n);
    vector<int> b(n);
    vector<pi> f(n),t(n);
    rep(i,n){
        cin >>a[i] >>d[i];
        b[i] = a[i]+d[i];

        f[i] = {-a[i],i};
        t[i] = {-b[i],i};
    }

    int ans = 0;
    rep(i,n)rep(j,i){
        P ri(min(f[i],t[i]), max(f[i],t[i]));
        P rj(min(f[j],t[j]), max(f[j],t[j]));
        pi L = max(ri.fi,rj.fi), R = min(ri.se,rj.se);

        if(d[i]*d[j]<0){
            if(L <= R) ++ans;
        }
        else{
            if(L <= R){
                if( (L==ri.fi&&R==ri.se) || (L==rj.fi&&R==rj.se) ) ++ans;
                else ans += 2;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
