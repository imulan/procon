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

    map<int,int> A,B;
    vector<int> v;
    rep(i,n){
        int a,b;
        cin >>a >>b;
        ++A[a];
        ++B[b];
        v.pb(a);
        v.pb(b);
    }

    sort(all(v));
    v.erase(unique(all(v)), v.end());

    int ans = 0;
    int now = 0;
    for(int i:v){
        now += A[i];
        ans = max(ans,now);
        now -= B[i];
    }
    cout << ans << endl;
    return 0;
}
