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
    rep(i,n) cin >>a[i] >>b[i];

    int m;
    cin >>m;
    vector<int> x(m),y(m);
    rep(i,m) cin >>x[i] >>y[i];

    vector<int> ct(m);
    rep(i,n){
        rep(j,m) ct[j] += (x[j]<=a[i] && b[i]<=y[j]);
    }

    int M = *max_element(all(ct));
    if(M==0) cout << 0 << endl;
    else{
        rep(i,m)if(ct[i]==M) cout << i+1 << endl;
    }
    return 0;
}
