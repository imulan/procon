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

const int N = 1000010;
int t[N]={};

int main(){
    t[4] = 1;
    for(int i=5; i<N; ++i){
        for(int j=1; j<=4; ++j) (t[i] += t[i-j]) %= 17;
    }

    // find cycle
    // for(int i=5; i<N; ++i){
    //     if(t[i]==1 && t[i-1]==0 && t[i-2]==0 && t[i-3]==0) dbg(i);
    // }

    int q;
    cin >>q;
    while(q--){
        ll n;
        cin >>n;
        cout << t[(n-1)%4912 + 1] << endl;
    }
    return 0;
}
