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

const int INF = 19191919;

int main(){
    int n,m;
    while(scanf(" %d %d", &n, &m),n){
        vector<int> s(n);
        rep(i,n) scanf(" %d", &s[i]);

        auto f = [&](int x){
            if(1+x <= s[0]) return INF;

            int L = 1;
            int ct = 0;
            int idx = 0;
            while(L+x <= s[n-1]){

                int nL = L+1;
                for(int i:{idx-1,idx})if(i>=0 && s[i]<L+x){
                    int add = max(1, x-abs(L-s[i]));
                    nL = max(nL, L+add);
                }

                ++ct;
                L = nL;
                while(idx < n-1 && s[idx] <= L) ++idx;
            }
            return ct+1;
        };

        int ok = 0, ng = 2222222;
        while(ng-ok>1){
            int x = (ok+ng)/2;
            if(f(x)>=m) ok = x;
            else ng = x;
        }

        if(ok==0 || f(ok)==INF) ok = -1;
        printf("%d\n", ok);
    }
    return 0;
}
