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

int f(int x){
    map<int,int> d;
    int t = x;
    for(int i=2; i*i<=x; ++i){
        while(t%i==0){
            ++d[i];
            t/=i;
        }
    }
    if(t>1) ++d[t];

    int ret = 1;
    for(const auto &p:d) ret *= p.se+1;
    return ret;
}

int main(){
    int n;
    cin >>n;

    int a = 1;
    while(f(a)!=n) ++a;
    cout << a << endl;
    return 0;
}
