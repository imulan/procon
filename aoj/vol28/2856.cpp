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
    int n,h,w;
    cin >>n >>h >>w;

    vector<int> b(w*n+1);
    rep(i,n){
        int x;
        cin >>x;

        int mul = 1;
        if(i%2 == 1) mul = -1;

        int pos = w*i + mul*x;
        ++b[pos];
        --b[pos+w];
    }

    rep(i,w*n) b[i+1] += b[i];

    int ans = 0;
    rep(i,w*n)if(b[i] == 0) ans += h;
    cout << ans << endl;
    return 0;
}
