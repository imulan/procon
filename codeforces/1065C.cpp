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

const int N = 200002;
int ct[N];

int main(){
    int n,k;
    scanf(" %d %d", &n, &k);

    rep(i,n){
        int h;
        scanf(" %d", &h);
        ++ct[1];
        --ct[h+1];
    }

    rep(i,N-1) ct[i+1] += ct[i];

    int ans = 0;
    int x = 0;
    for(int i=N-1; i>0; --i){
        if(ct[i] == n) break;

        if(x+ct[i] > k){
            ++ans;
            x = 0;
        }
        x += ct[i];
    }
    ans += (x!=0);
    printf("%d\n", ans);
    return 0;
}
