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
    int w,h;
    char c;
    cin >>w >>h >>c;

    vector<string> s(h,string(w,'.'));

    for(int i:{0,h-1})rep(j,w) s[i][j] = '-';
    for(int j:{0,w-1})rep(i,h) s[i][j] = '|';
    s[h/2][w/2] = c;
    for(int i:{0,h-1})for(int j:{0,w-1}) s[i][j] = '+';

    rep(i,h) cout << s[i] << "\n";
    return 0;
}
