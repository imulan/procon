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

bool solve(){
    int n;
    cin >>n;

    map<int,int> m;
    rep(i,4*n){
        int a;
        cin >>a;
        ++m[a];
    }

    vector<int> v;
    for(const auto &p:m){
        int x = p.se;
        if(x%2==1) return false;
        rep(i,x/2) v.pb(p.fi);
    }

    sort(all(v));
    int t = v[0]*v[2*n-1];
    rep(i,n){
        int s = v[i]*v[2*n-1-i];
        if(t != s) return false;
    }
    return true;
}

int main(){
    int q;
    cin >>q;
    while(q--) cout << (solve()?"YES":"NO") << "\n";
    return 0;
}
