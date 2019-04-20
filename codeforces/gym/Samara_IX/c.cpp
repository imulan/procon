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

bool check(int x, int y, int z){
    vector<int> v({x,y,z});
    sort(all(v));
    return v[0]+v[1] > v[2];
}

int solve(){
    int n;
    cin >>n;
    vector<int> l(n);
    rep(i,n) cin >>l[i];

    sort(all(l));

    auto valid = [&](int x){
        vector<pi> v({{l[0],l[1]}, {l[0],l[n-1]}, {l[n-2],l[n-1]}});
        for(const auto &p:v){
            if(!check(x, p.fi, p.se)) return false;
        }
        return true;
    };

    int m = max(l[0], l[n-1]-l[0]+1);
    for(int c:{l[0],l[n-1],m}){
        if(valid(c)) return c;
    }
    return -1;
}

int main(){
    int a = solve();
    if(a == -1) cout << "NO" << "\n";
    else cout << "YES\n" << a << "\n";
    return 0;
}
