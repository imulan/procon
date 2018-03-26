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

int rev(int x, int l, int r){
    int n = x-l;
    return r-n;
}

int main(){
    int n,a,d,m;
    cin >>n >>a >>d >>m;

    vector<int> x(m),y(m),z(m);
    rep(i,m){
        cin >>x[i] >>y[i] >>z[i];
        --y[i];
        --z[i];
    }

    int k;
    cin >>k;
    --k;

    int idx = k;
    for(int i=m-1; i>=0; --i){
        if(x[i]==0){
            if(y[i]<=idx && idx<=z[i]) idx = rev(idx, y[i], z[i]);
        }
    }

    ll val = a+idx*d;
    rep(i,m){
        if(y[i]<=idx && idx<=z[i]){
            if(x[i]==0) idx = rev(idx, y[i], z[i]);
            if(x[i]==1) ++val;
            if(x[i]==2) val /= 2;
        }
    }
    cout << val << endl;
    return 0;
}
