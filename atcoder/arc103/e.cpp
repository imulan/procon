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
    string s;
    cin >>s;
    int n = s.size();

    vector<bool> t(n+1);
    rep(i,n) t[i+1] = (s[i]=='1');
    t[0] = true;

    bool ok = !t[n] & t[1] & t[n-1];
    for(int i=1; i<n; ++i) ok &= (t[i]==t[n-i]);
    if(!ok){
        cout << -1 << "\n";
        return 0;
    }

    int par = n;
    for(int i=n-1; i>0; --i){
        cout << par << " " << i << "\n";
        if(i<n-1 && t[i]) par = i;
    }
    return 0;
}
