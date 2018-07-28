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
    int n,k;
    cin >>n >>k;

    map<int,int> m;
    rep(i,n){
        int a;
        cin >>a;
        m[a] = i;
    }

    string ans = "NO";
    vector<int> v;

    if(m.size()>=k){
        ans = "YES";
        for(const auto &p:m){
            v.pb(p.se+1);
            if(v.size()==k) break;
        }
    }

    cout << ans << endl;
    for(int i:v) cout << i << " ";
    cout << endl;
    return 0;
}
