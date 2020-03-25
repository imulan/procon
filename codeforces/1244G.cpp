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

int main(){
    int n;
    ll k;
    scanf(" %d %lld", &n, &k);

    vector<int> p(n),q(n);
    rep(i,n) p[i] = q[i] = i+1;

    do{
        ll t = 0;
        rep(i,n) t += max(p[i],q[i]);

        int d = 0;
        rep(i,n){
            int pos = q[i]-1;
            d += abs(pos-i);
        }


        printf(" s = %lld  d = %d :",t,d); dbg(q);

    }while(next_permutation(all(q)));

    return 0;
}
