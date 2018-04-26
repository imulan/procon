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

bool solve(ll x, ll y){
    if(y==0) return false;
    if(y==1) return x==0;

    x -= y-1;
    if(x<0) return false;

    return x%2 == 0;
}

int main(){
    ll x,y;
    cin >>x >>y;
    cout << (solve(x,y)?"Yes":"No") << endl;
    return 0;
}
