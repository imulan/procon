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
    string s;
    cin >>n >>s;

    int ans = n;

    string t = "";
    rep(i,n){
        t += s[i];
        int L = i+1;
        int R = n-L;

        // copy
        if(L<=R){
            string c = s.substr(i+1,L);
            if(t==c) ans = min(ans, n-L+1);
        }
    }
    cout << ans << endl;
    return 0;
}
