#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

using pi = pair<int,int>;

int main(){
    int n;
    cin >>n;

    vector<int> a(n),b(n);
    rep(i,n) cin >>a[i];
    rep(i,n) cin >>b[i];

    map<pi,int> m;
    int z = 0;
    rep(i,n){
        if(a[i] == 0) z += (b[i]==0);
        else{
            if(a[i]<0){
                a[i] *= -1;
                b[i] *= -1;
            }

            int g = __gcd(a[i], abs(b[i]));
            a[i] /= g;
            b[i] /= g;
            ++m[{a[i],b[i]}];
        }
    }

    int ans = z;
    for(const auto &p:m) ans = max(ans, z+p.se);
    cout << ans << "\n";
    return 0;
}
