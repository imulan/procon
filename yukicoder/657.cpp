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

    int q;
    cin >>q;
    while(q--){
        int n;
        cin >>n;
        cout << t[n] << endl;
    }
    return 0;
}
