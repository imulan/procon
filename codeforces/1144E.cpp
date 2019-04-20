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
    string s,t;
    cin >>n >>s >>t;

    vector<int> a(n+1);
    for(int i=n; i>=1; --i){
        a[i] += s[i-1]-'a'+t[i-1]-'a';
        if(a[i]>=26){
            a[i-1]++;
            a[i] -= 26;
        }
    }

    rep(i,n+1){
        if(a[i]%2==1){
            a[i+1] += 26;
        }
        a[i]/=2;
    }

    string z(n,' ');
    for(int i=1; i<=n; ++i) z[i-1] = 'a'+a[i];
    cout << z << "\n";
    return 0;
}
