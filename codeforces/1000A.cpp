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
    cin >>n;

    map<string,int> a,b;
    rep(i,n){
        string s;
        cin >>s;
        ++a[s];
    }
    rep(i,n){
        string s;
        cin >>s;
        ++b[s];
    }

    int ans = 0;
    for(string s:vector<string>({"S","M","L","XS","XXS","XXXS","XL","XXL","XXXL",})){
        ans += abs(a[s]-b[s]);
    }
    cout << ans/2 << endl;
    return 0;
}
