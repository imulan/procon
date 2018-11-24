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
    vector<int> a(n);
    rep(i,n) cin >>a[i];

    int sa = 0;
    rep(i,n) sa += a[i];

    int val = 123456789;
    int idx = -1;
    rep(i,n){
        int d = abs(sa - n*a[i]);
        if(d < val){
            val = d;
            idx = i;
        }
    }
    cout << idx << endl;
    return 0;
}
