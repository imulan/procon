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

int main(){
    int n,q;
    scanf(" %d %d", &n, &q);

    vector<int> ct(31);
    rep(i,n){
        int a;
        scanf(" %d", &a);

        rep(j,31){
            if((1<<j)==a) ++ct[j];
        }
    }

    while(q--){
        int b;
        scanf(" %d", &b);

        int rem = b;
        int ans = 0;
        for(int i=30; i>=0; --i){
            int c = 1<<i;
            if(rem-c<0) continue;

            int num = rem/c;
            num = min(num,ct[i]);
            ans += num;
            rem -= c*num;
        }

        if(rem != 0) ans = -1;
        printf("%d\n", ans);
    }

    return 0;
}
