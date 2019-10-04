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

int f(int x){
    ++x;
    while(x%10 == 0) x/=10;
    return x;
}

int main(){
    int n;
    cin >>n;

    set<int> s;
    while(!s.count(n)){
        s.insert(n);
        n = f(n);
    }
    cout << s.size() << "\n";
    return 0;
}
