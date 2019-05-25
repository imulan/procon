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

vector<int> divisor(int x){
    vector<int> ret;
    for(int i=1; i*i<=x; ++i){
        if(x%i==0){
            ret.pb(i);
            if(i != x/i) ret.pb(x/i);
        }
    }
    return ret;
}

int main(){
    int n;
    scanf(" %d", &n);

    vector<int> a(n),b(n);
    rep(i,n) scanf(" %d %d", &a[i], &b[i]);

    vector<int> d;
    for(int i:divisor(a[0])) d.pb(i);
    for(int i:divisor(b[0])) d.pb(i);
    sort(all(d));
    d.erase(unique(all(d)), d.end());

    int D = d.size();
    int idx = D-1;
    while(1){
        bool ok = true;
        rep(i,n){
            if(a[i]%d[idx]!=0 && b[i]%d[idx]!=0){
                ok = false;
                break;
            }
        }
        if(ok) break;
        --idx;
    }
    printf("%d\n", d[idx]);
    return 0;
}
