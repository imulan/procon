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
    int n,k;
    scanf(" %d %d", &n, &k);

    if((ll)k*(k-1) < n){
        printf("NO\n");
        return 0;
    }

    printf("YES\n");
    int ct = 0;
    for(int j=1; j<k; ++j){
        rep(i,k){
            int x = i+1;
            int y = (i+j)%k+1;
            printf("%d %d\n", x, y);

            ++ct;
            if(ct == n) return 0;
        }
    }
    return 0;
}
