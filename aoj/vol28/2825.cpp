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
    int n,m;
    while(scanf(" %d %d", &n, &m),n){
        vector<int> mx(n),mn(n);
        rep(i,m){
            int s,k;
            scanf(" %d %d", &s, &k);

            rep(j,k){
                int c;
                scanf(" %d", &c);
                --c;

                mx[c] += s;
                if(k==1) mn[c] +=s;
            }
        }

        multiset<int> s;
        rep(i,n) s.insert(mn[i]);

        int ans = 0;
        rep(i,n){
            s.erase(s.find(mn[i]));
            int MN = *s.begin();
            ans = max(ans, mx[i]-MN);
            s.insert(mn[i]);
        }
        cout << ans+1 << endl;
    }
    return 0;
}
