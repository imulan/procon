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

vector<int> divisor(int n){
    vector<int> ret;
    for(int i=1; i*i<=n; ++i){
        if(n%i == 0){
            ret.pb(i);
            if(i != n/i) ret.pb(n/i);
        }
    }
    // sort(all(ret));
    return ret;
}

const int N = 1000002;
// int idx[N];
ll ct[N];
vector<int> divs[N];

int main(){

    int n,k;
    scanf(" %d %d", &n, &k);

    vector<int> a(n);
    rep(i,n) scanf(" %d", &a[i]);
    sort(all(a));

    // vector<int> dk = divisor(k);
    // int D = dk.size();

    vector<int> da;
    rep(i,n){
        if( !(i>0 && a[i-1] == a[i]) ) da = divisor(a[i]);
        for(int j:da) divs[j].pb(i);
    }

    // rep(i,D){
    //     printf(" %d (%d) : ",i,dk[i]);
    //     dbg(divs[i]);
    // }

    rep(i,N){
        const vector<int> &div = divs[i];
        int sz = div.size();
        if(sz <= 1) continue;

        // printf(" %d :",i);
        // dbg(div);

        int r = sz-1;
        rep(l,sz){
            int lidx = div[l];
            while(r>=0){
                int ridx = div[r];
                if(a[lidx] + a[ridx] >= k) --r;
                else break;
            }

            int num = sz-1 - max(l,r);
            // printf(" %d %d  %d\n",i,l,num);
            ct[i] += num;
        }
    }

    ll ans = 0;
    for(int i=N-1; i>0; --i){
        // dbg(i);
        for(int j=i*2; j<N; j+=i){
            ct[i] -= ct[j];
        }

        if(k%i == 0) ans += ct[i];
    }
    cout << ans << endl;
    return 0;
}
