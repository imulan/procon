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

    int x=0,y=0;
    int ans = 0;
    int st = 0;
    rep(i,n){
        if(s[i]=='U') ++y;
        else ++x;

        if(x<y){
            if(st == 1) ++ans;
            st = 2;
        }
        if(x>y){
            if(st == 2) ++ans;
            st = 1;
        }
    }
    cout << ans << endl;
    return 0;
}
