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

const int N = 100001;
vector<int> p[N];

int main(){
    int n;
    scanf(" %d", &n);
    vector<int> a(n);
    rep(i,n){
        scanf(" %d", &a[i]);
        p[a[i]].pb(i);
    }

    vector<int> ans(n);
    int now = 0;
    for(int i=N-1; i>0; --i){
        reverse(all(p[i]));
        for(int j:p[i]){
            // printf(" %d: %d\n",i,j);
            ans[j] = now++;
        }
    }

    rep(i,n) printf("%d%c", ans[i]+1, " \n"[i==n-1]);
    return 0;
}
