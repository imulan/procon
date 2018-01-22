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

const string NG = "impossible";

ll f(ll x){
    return x*(x+1)/2;
}

string solve(){
    ll x,n;
    cin >>x >>n;

    ll s = f(n)-x;
    if(n==2 || n==3 || s%2 == 1) return NG;

    string ans(n,'0');
    s /= 2;
    for(int i=n; i>0; --i){
        if(i==x){
            ans[i-1] = '2';
            continue;
        }

        // dbg(s);dbg(i);
        if(s-i>=0 && s-i!=x){
            s -= i;
            ans[i-1] = '1';
        }
    }

    assert(s==0);
    if(s != 0) return NG;
    return ans;
}

int main(){
    int T;
    cin >>T;
    while(T--) cout << solve() << endl;
    return 0;
}
