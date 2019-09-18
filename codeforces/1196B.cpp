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

void solve(){
    int n,k;
    scanf(" %d %d", &n, &k);

    int odd = 0;
    vector<int> a(n);
    rep(i,n){
        scanf(" %d", &a[i]);
        odd += a[i]%2;
    }

    if(odd%2==k%2 && odd>=k){
        vector<int> ans(k);
        int idx = 0;
        rep(i,n){
            if(idx >= k-1) break;
            if(a[i]%2==1) ans[idx++] = i+1;
        }
        ans[k-1] = n;

        printf("YES\n");
        rep(i,k) printf("%d%c", ans[i], " \n"[i==k-1]);
    }
    else printf("NO\n");
}

int main(){
    int q;
    scanf(" %d", &q);
    while(q--) solve();
    return 0;
}
