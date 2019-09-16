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
    vector<int> a(n);
    rep(i,n){
        cin >>a[i];
        --a[i];
    }

    for(int x:{-1,1}){
        bool ok = true;
        rep(i,n){
            int nx = (i+1)%n;
            if((a[i]+x+n)%n != a[nx]) ok = false;
        }
        if(ok) return true;
    }

    return false;
}

int main(){
    int q;
    cin >>q;
    while(q--) cout << (solve()?"YES":"NO") << "\n";
    return 0;
}
