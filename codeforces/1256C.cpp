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

int main(){
    int n,m,d;
    cin >>n >>m >>d;

    int sc = 0;
    vector<int> c(m);
    rep(i,m){
        cin >>c[i];
        sc += c[i];
    }

    if(sc+(m+1)*(d-1)<n){
        cout << "NO\n";
        return 0;
    }

    int sp = n-sc;
    vector<int> blank(m+1);
    while(sp>0){
        rep(i,m+1)if(sp>0){
            ++blank[i];
            --sp;
        }
    }
    vector<int> p(n);
    int idx = 0;
    rep(i,m){
        idx += blank[i];
        rep(j,c[i]){
            p[idx] = i+1;
            ++idx;
        }
    }

    cout << "YES\n";
    rep(i,n) cout << p[i] << " \n"[i==n-1];
    return 0;
}
