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

using ull = unsigned long long;

bool valid(int b, ull n){
    for(int i=2; i<b; ++i){
        while(n%i==0) n /= i;
    }
    return n==1;
}

int main(){
    int b;
    ull n;
    cin >>b >>n;

    if(!valid(b,n)){
        cout << "impossible" << endl;
        return 0;
    }

    auto check = [&](ull x){
        vector<int> v;



        return true;
    };

    ull ng=0, ok=(1LL<<63);
    while(ok-ng>1){
        ull mid = (ng+ok)/2;
        if(check(mid)) ok = mid;
        else ng = mid;
    }
    cout << ok << endl;
    return 0;
}
