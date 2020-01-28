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

const vector<int> NG(1,-1);
vector<int> f(int n){
    int t = n;
    vector<int> a;
    for(int i=2; i*i<=n; ++i){
        if(t%i==0){
            a.pb(i);
            t /= i;
        }

        if(a.size() == 2){
            if(a.back() < t){
                a.pb(t);
                return a;
            }
            else return NG;
        }
    }

    return NG;
}

void solve(){
    int n;
    cin >>n;

    vector<int> a = f(n);
    if(a.size() == 3){
        cout << "YES\n";
        rep(i,3) cout << a[i] << " \n"[i==2];
    }
    else cout << "NO\n";
}

int main(){
    int t;
    cin >>t;
    while(t--) solve();
    return 0;
}
