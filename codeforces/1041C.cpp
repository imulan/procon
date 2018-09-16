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
    int n,m,d;
    scanf(" %d %d %d", &n, &m, &d);

    set<int> s;
    vector<int> a(n);
    map<int,int> M;
    rep(i,n){
        scanf(" %d", &a[i]);
        M[a[i]] = i;
        s.insert(a[i]);
    }

    vector<int> ans(n);
    for(int i=1; i<=n; ++i){
        if(s.empty()) break;
        int val = *s.begin();
        s.erase(val);
        ans[M[val]] = i;

        while(1){
            auto itr = s.upper_bound(val + d);
            if(itr == s.end()) break;

            val = *itr;
            s.erase(val);
            ans[M[val]] = i;
        }
    }

    int D = 0;
    rep(i,n) D = max(D,ans[i]);
    printf("%d\n",D);
    rep(i,n) printf("%d%c", ans[i], " \n"[i==n-1]);
    return 0;
}
