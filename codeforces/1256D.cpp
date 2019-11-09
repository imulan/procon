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

string solve(){
    int n;
    ll k;
    string s;
    cin >>n >>k >>s;

    int zero = 0, one = 0;
    vector<int> z;
    rep(i,n){
        if(s[i] == '1') ++one;
        else{
            ++zero;
            z.pb(one);
        }
    }

    rep(i,zero){
        if(z[i]<=k){
            k -= z[i];
            z[i] = 0;
        }
        else{
            z[i] -= k;
            k = 0;
        }
    }

    int zidx = 0;
    string a = "";
    rep(i,one+1){
        while(zidx<zero && z[zidx] == i){
            ++zidx;
            a += '0';
        }

        if(i<one) a += '1';
    }
    return a;
}

int main(){
    int q;
    cin >>q;
    rep(i,q) cout << solve() << "\n";
    return 0;
}
