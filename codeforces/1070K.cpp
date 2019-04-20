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
    int n,k;
    scanf(" %d %d", &n, &k);

    vector<int> a(n);
    rep(i,n) scanf(" %d", &a[i]);

    int sa = 0;
    rep(i,n) sa += a[i];

    if(sa%k != 0){
        printf("No\n");
        return 0;
    }
    int b = sa/k;

    vector<int> ans;
    int s = 0;
    while(s<n){
        int e = s;
        int sum = 0;
        while(e<n && sum+a[e] <= b){
            sum += a[e];
            ++e;
        }

        if(sum != b){
            printf("No\n");
            return 0;
        }

        ans.pb(e-s);
        s = e;
    }

    int sz = ans.size();
    assert(sz == k);
    printf("Yes\n");
    rep(i,sz) printf("%d%c", ans[i], " \n"[i==sz-1]);
    return 0;
}
