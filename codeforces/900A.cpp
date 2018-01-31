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
    int n;
    cin >>n;

    int pos = 0, neg = 0;
    rep(i,n){
        int x,y;
        cin >>x >>y;
        if(x>0) ++pos;
        else ++neg;
    }

    string ans = "No";
    if(pos<=1 || neg<=1) ans = "Yes";
    cout << ans << endl;
    return 0;
}
