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

const int a[3] = {10,7,7};

int main(){
    int n,k;
    cin >>n >>k;

    vector<int> v[3];
    rep(i,n){
        int x[3];
        rep(j,3){
            cin >>x[j];
            --x[j];
        }

        int idx = 0;
        rep(j,3)if(x[j]>0) idx = j;

        v[idx].pb(x[idx]);
    }
    rep(i,3) sort(all(v[i]));

    auto check = [&](int x){
        int ct = 0;
        rep(i,3){
            int lim = x*a[i]-k;
            if(lim<0) return false;

            for(int j:v[i]){
                if(lim - j < 0) break;
                lim -= j;
                ++ct;
            }
        }

        return ct>=k;
    };

    int ng=0, ok=n*15;
    while(ok-ng>1){
        int mid = (ok+ng)/2;
        if(check(mid)) ok = mid;
        else ng = mid;
    }
    cout << ok << "\n";
    return 0;
}
