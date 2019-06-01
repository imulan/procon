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

const int N = 8;

int ask(int x){
    cout << x+1 << endl;

    string s;
    cin >>s;

    if(s=="Yes") return -1;
    return s=="Near";
}

int main(){
    int n,k;
    cin >>n >>k;

    // make graph
    vector<pair<int,int>> e;
    for(int i=N; i<n; ++i){
        int mask = i-N;
        rep(j,N)if(mask>>j&1){
            e.pb({j+1, i+1});
        }
    }

    cout << e.size() << endl;
    for(const auto &p:e) cout << p.fi << " " << p.se << endl;

    auto game = [&](){
        int m = 0;
        rep(i,N){
            int a = ask(i);
            if(a == -1) return;
            m |= a<<i;
        }

        assert(ask(N+m) == -1);
    };

    while(k--) game();
    return 0;
}
