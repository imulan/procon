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

bool check(const vector<ll> &a){
    int n = a.size();
    ll sum = 0;
    rep(i,n) sum += a[i];
    if(sum%2==0){

        set<ll> pre;
        ll t = 0;
        rep(i,n){
            t += a[i];
            pre.insert(t);
        }

        t = 0;
        rep(i,n){
            if(pre.count(a[i]+sum/2)) return true;
            t += a[i];
            pre.erase(t);
        }
    }
    return false;
}

bool solve(){
    int n;
    cin >>n;
    vector<ll> a(n);
    rep(i,n) cin >>a[i];

    bool ret = check(a);
    reverse(all(a));
    ret |= check(a);
    return ret;
}

int main(){
    cout << (solve()?"YES":"NO") << endl;
    return 0;
}
