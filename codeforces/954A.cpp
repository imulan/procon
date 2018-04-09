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
        if(idx+1<n){
            if((s[idx]=='U' && s[idx+1]=='R') || (s[idx+1]=='U' && s[idx]=='R')){
                idx += 2;
            }
            else ++idx;
        }
        else ++idx;
        ++ans;
    }
    cout << ans << endl;
    return 0;
}
