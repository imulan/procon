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

int main(){
    int n;
    cin >>n;
    vector<int> a(n),b(n);
    rep(i,n) cin >>a[i];
    rep(i,n) cin >>b[i];

    vector<int> ct_b(n+1);
    rep(i,n) ++ct_b[b[i]];

    bool ok = true;
    vector<int> c(n),d(n);
    rep(i,n){
        if(ct_b[a[i]] == 0){
            ok = false;
            c[i] = 1;
            d[i] = 2;
        }
        else c[i] = d[i] = 1;
    }


    if(ok) cout << "Yes" << endl;
    else{
        cout << "No" << endl;
        rep(i,n) cout << c[i] << " \n"[i==n-1];
        rep(i,n) cout << d[i] << " \n"[i==n-1];
    }
    return 0;
}
