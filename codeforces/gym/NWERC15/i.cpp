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

ll pow(ll x, int n){
    ll ret = 1;
    rep(i,n) ret*=x;
    return ret;
}

int main(){
    string s;
    cin >>s;

    int n = s.size();
    ll lx = 0, rx = pow(2,n);
    ll ly = 0, ry = pow(2,n);
    rep(i,n){
        int v = s[i]-'0';

        ll mx = (lx+rx)/2, my = (ly+ry)/2;
        if(v<2){
            ry = my;
        }
        else{
            ly = my;
        }

        if(v%2==0){
            rx = mx;
        }
        else{
            lx = mx;
        }
    }

    printf("%d %lld %lld\n",n,lx,ly);
    return 0;
}
