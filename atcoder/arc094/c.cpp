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
    int v[3];
    rep(i,3) cin >>v[i];
    sort(v,v+3);

    int ct[2]={};
    rep(i,3) ++ct[v[i]%2];

    int ans = 0;

    if(ct[0]==2 || ct[1]==2){
        int f = 0;
        if(ct[1]==2) f = 1;

        ++ans;
        rep(i,3)if(v[i]%2==f) ++v[i];
        sort(v,v+3);
    }
    rep(i,3) ans += (v[2]-v[i])/2;
    cout << ans << endl;
    return 0;
}
