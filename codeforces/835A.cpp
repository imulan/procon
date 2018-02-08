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

int f(int s, int v, int t){
    return 2*t + v*s;
}

int main(){
    int s,v1,v2,t1,t2;
    cin >>s >>v1 >>v2 >>t1 >>t2;

    string ans = "Friendship";
    if(f(s,v1,t1) < f(s,v2,t2)) ans = "First";
    else if(f(s,v1,t1) > f(s,v2,t2)) ans = "Second";
    cout << ans << endl;
    return 0;
}
