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

int solve(){
    int n;
    cin >>n;
    vector<int> c(n);
    rep(i,n) cin >>c[i];

    int q;
    cin >>q;
    vector<int> t(q),x(q),d(q);
    rep(i,q){
        cin >>t[i] >>x[i] >>d[i];
        --x[i];
    }

    vector<int> a(n);
    rep(i,q){
        if(t[i]==1){
            a[x[i]] += d[i];
            if(a[x[i]] > c[x[i]]) return x[i]+1;
        }
        else{
            a[x[i]] -= d[i];
            if(a[x[i]] < 0) return x[i]+1;
        }
    }
    return 0;
}

int main(){
    cout << solve() << endl;
    return 0;
}
