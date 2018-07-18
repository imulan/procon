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

vector<pi> f(int n, int m){
    vector<pi> p;
    int e = 0;

    for(int i=2; i<=n; ++i){
        p.pb({i,1});
        ++e;
    }
    if(e>=m) return p;

    for(int i=3; i<=n; ++i){
        for(int j=2; j<i; ++j){
            if(__gcd(i,j)==1){
                ++e;
                p.pb({i,j});
                if(e==m) return p;
            }
        }
    }
    return p;
}

int main(){
    int n,m;
    cin >>n >>m;

    vector<pi> p=f(n,m);

    if(m<n-1 || p.size()<m){
        cout << "Impossible" << endl;
    }
    else{
        cout << "Possible" << endl;
        for(const auto x:p) cout << x.fi << " " << x.se << endl;
    }
    return 0;
}
