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

int f(vector<int> ct){
    int sz = ct.size();
    int ret = 0;
    for(int i=sz; i>=3; --i){
        rep(j,sz-i+1){
            int num = 12345;
            for(int k=j; k<j+i; ++k) num = min(num, ct[k]);
            ret += 3*num;
            for(int k=j; k<j+i; ++k) ct[k] -= num;
        }
    }

    rep(i,sz) ret += ct[i];
    return ret;
}

int main(){
    string s;
    cin >>s;

    vector<int> a(26),d(10);
    for(char c:s){
        if(isdigit(c)) ++d[c-'0'];
        else ++a[c-'a'];
    }

    cout << f(a) + f(d) << endl;
    return 0;
}
