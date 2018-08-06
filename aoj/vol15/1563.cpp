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
    int n,a,d,m;
    cin >>n >>a >>d >>m;

    map<int,int> c;
    rep(i,m){
        int x,y,z;
        cin >>x >>y >>z;
        --y;
        --z;

        if(!c.count(y)) c[y] = a+y*d;
        if(!c.count(z)) c[z] = a+z*d;

        if(x==0) swap(c[y],c[z]);
        else c[y] = c[z];
    }

    int k;
    cin >>k;
    --k;

    int ans = a+k*d;
    if(c.count(k)) ans = c[k];
    cout << ans << endl;
    return 0;
}
