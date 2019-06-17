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

char solve(){
    string s;
    cin >>s;
    int n = s.size();

    if(n==2) return 'N';

    int b = 0;
    for(int i:s) b += (i=='B');

    if(n==3){
       if(b==1) return 'Y';
       return 'N';
    }

    if(2<=b && b<=n-2) return 'Y';
    return 'N';
}

int main(){
    int T;
    cin >>T;
    rep(i,T) printf("Case #%d: %c\n", i+1, solve());
    return 0;
}
