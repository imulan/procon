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

int lcm(int x, int y){
    return x/__gcd(x,y)*y;
}

vector<int> divisor(int n){
    vector<int> ret;
    for(int i=1; i*i<=n; ++i){
        if(n%i==0){
            ret.pb(i);
            if(n/i!=i) ret.pb(n/i);
        }
    }
    sort(all(ret));
    return ret;
}

const int N = 10010;
multiset<int> d[N];

int main(){
    int n;
    cin >>n;
    vector<int> a(n);
    rep(i,n) cin >>a[i];

    for(int i=1; i<n; ++i){
        for(int j:divisor(a[i])) d[j].insert(a[i]);
    }

    vector<int> ans;
    ans.pb(a[0]);
    for(int i=1; i<n; ++i){
        int m = N*N;
        int nx = N;

        int now = ans.back();
        for(int j:divisor(now))if(!d[j].empty()){
            int tmp = *d[j].begin();

            int L = lcm(now,tmp);
            if(L<m || (L==m && tmp<nx)){
                m = lcm(now,tmp);
                nx = tmp;
            }
        }

        assert(nx!=N);
        for(int j:divisor(nx)) d[j].erase(d[j].find(nx));
        ans.pb(nx);
    }

    rep(i,n) cout << ans[i] << " \n"[i==n-1];
    return 0;
}
