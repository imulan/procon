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

const int N = 1000001;
int ct[N]={};
bool ok[N];

int solve(){
    int n,A;
    cin >>n >>A;
    vector<int> c(n);
    rep(i,n) cin >>c[i];

    fill(ok,ok+N,true);
    int a=0;
    rep(i,n){
        if(c[i]==A) ++a;
        else{
            if(ct[c[i]]<a) ok[c[i]] = false;
            ++ct[c[i]];
        }
    }

    for(int i=1; i<N; ++i)if(i!=A && ct[i]>=a && ok[i]) return i;
    return -1;
}

int main(){
    cout << solve() << endl;
    return 0;
}
