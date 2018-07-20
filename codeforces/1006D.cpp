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
    string a,b;
    cin >>n >>a >>b;

    int ans = 0;
    rep(i,n/2){
        int j = n-1-i;
        char a1 = a[i], a2 = a[j];
        char b1 = b[i], b2 = b[j];

        if((a1==b1 && a2==b2) || (a1==b2 && a2==b1) || (a1==a2 && b1==b2)) ans += 0;
        else if(a1==b1 || a1==b2 || a2==b1 || a2==b2 || b1==b2) ans += 1;
        else ans += 2;
    }
    if(n%2==1) ans += (a[n/2]!=b[n/2]);
    cout << ans << endl;
    return 0;
}
