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

    int ans = 0;
    int idx = 0;
    while(idx<n){
        if(s[idx]=='x'){
            int start = idx;
            while(idx<n && s[idx]=='x') ++idx;
            int L = idx-start;
            ans += max(0,L-2);
        }
        else ++idx;
    }
    cout << ans << endl;
    return 0;
}
