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

using P = pair<string,int>;

int main(){
    int n;
    cin >>n;

    vector<P> v(n);
    rep(i,n){
        string s;
        int p;
        cin >>s >>p;
        v[i] = {s,-p};
    }

    vector<P> s(v);
    sort(all(s));
    rep(i,n){
        int a = 0;
        while(s[i] != v[a]) ++a;
        cout << a+1 << endl;
    }
    return 0;
}
