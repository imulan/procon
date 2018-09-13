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

bool solve(){
    ll n,c;
    scanf(" %lld %lld", &n, &c);

    if(n==1) return true;

    ll d = 1;
    if(n%2==0 && c%n==0) d = 2;

    ll p = 2*c - (n-1)*n*d;
    ll q = 2*n;
    return (p>0 && p%q==0);
}

int main(){
    int T;
    scanf(" %d", &T);
    while(T--){
        if(solve()) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
