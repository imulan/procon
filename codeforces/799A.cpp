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
    int n,t,k,d;
    cin >>n >>t >>k >>d;

    int F = t*((n+k-1)/k);

    int S = d;
    while(1){
        int a = k*(S/t);
        int b = k*((S-d)/t);
        if(a+b >= n) break;
        S++;
    }

    cout << ((F>S)?"YES":"NO") << endl;
    return 0;
}
