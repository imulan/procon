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
const int INF = 19191919;
bool prime[N];
int maxp[N];

int solve(){
    fill(prime,prime+N,true);
    prime[0] = prime[1] = false;
    for(int i=2; i<N; ++i){
        if(prime[i]){
            for(int j=2*i; j<N; j+=i) prime[j]=false;
            for(int j=i; j<N; j+=i) maxp[j] = max(maxp[j], i);
        }
    }

    int x2;
    cin >>x2;

    int ret = INF;
    for(int x1=x2-maxp[x2]+1; x1<=x2; ++x1)if(!prime[x1]){
        int x0 = x1 - maxp[x1] + 1;
        ret = min(ret, x0);
    }
    assert(ret<INF);
    return ret;
}

int main(){
    cout << solve() << endl;
    return 0;
}
