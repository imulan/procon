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
    int n;
    scanf(" %d", &n);

    vector<int> a(n);
    rep(i,n) scanf(" %d", &a[i]);

    multiset<int> s;
    rep(i,n){
        int b;
        scanf(" %d", &b);
        s.insert(b);
    }

    vector<int> c(n);
    rep(i,n){
        int t = (n-a[i])%n;
        auto itr = s.lower_bound(t);
        if(itr == s.end()) itr = s.begin();

        int v = *itr;
        c[i] = (a[i]+v)%n;

        s.erase(itr);
    }

    rep(i,n) printf("%d%c", c[i], " \n"[i==n-1]);
    return 0;
}
