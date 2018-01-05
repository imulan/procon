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

using pi = pair<int,int>;

void solve(){
    int n,m;
    cin >>n >>m;

    int A=(n+1)/2, B=n-A;
    if(A*B<m || m<n-1){
        cout << "NO" << endl;
        return;
    }
    
    vector<int> a(n);
    rep(i,n) a[i]=i+1;

    vector<pi> e;
    set<pi> s;

    int aa=1,bb=A+1;
    rep(i,n-1){
        e.pb({aa,bb});
        s.insert({aa,bb});
        if(i%2==0) ++aa;
        else ++bb;
        --m;
    }

    if(m>0){
        rep(i,A)rep(j,B){
            pi E(i+1,A+j+1);
            if(!s.count(E)){
                e.pb(E);
                s.insert(E);
                --m;
            }
            if(m==0){
                i=A;
                j=B;
            }
        }
    }

    cout << "YES" << endl;
    rep(i,n) cout << a[i] << " \n"[i==n-1];
    for(const auto &p:e) cout << p.fi << " " << p.se << endl;
}

int main(){
    solve();
    return 0;
}
