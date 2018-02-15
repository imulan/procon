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
    ll c[2];
    rep(i,2) cin >>c[i];

    int t = 0;
    ll num = 1;
    while(1){
        if(c[t]-num<0) break;

        c[t] -= num;
        ++num;
        t = !t;
    }

    string ans[2] = {"Vladik", "Valera"};
    cout << ans[t] << endl;
    return 0;
}
