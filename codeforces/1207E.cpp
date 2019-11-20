#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

int ask(const vector<int> &v){
    assert(v.size() == 100);
    cout << "?";
    for(int i:v) cout << " " << i;
    cout << endl;

    int x;
    cin >>x;
    return x;
}

int main(){
    vector<int> v;
    for(int i=1; i<=100; ++i) v.pb(i);
    int high = ask(v);
    high &= ((1<<7)-1)<<7;

    v.clear();
    for(int i=1; i<=100; ++i) v.pb(i<<7);
    int low = ask(v);
    low &= ((1<<7)-1);

    int ans = high|low;
    cout << "! " << ans << endl;
    return 0;
}
