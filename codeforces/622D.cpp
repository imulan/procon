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

    vector<int> x;

    vector<int> a;
    int s = 1;
    if(n%2==1) s = 2;
    for(int i=s; i<=n; i+=2) a.pb(i);

    for(int i:a) x.pb(i);
    reverse(all(a));
    for(int i:a) x.pb(i);

    vector<int> b;
    s = 2;
    if(n%2==1) s = 1;
    for(int i=s; i<n; i+=2) b.pb(i);

    for(int i:b) x.pb(i);
    x.pb(n);
    reverse(all(b));
    for(int i:b) x.pb(i);
    x.pb(n);

    rep(i,2*n) printf("%d%c", x[i], " \n"[i==2*n-1]);
    return 0;
}
