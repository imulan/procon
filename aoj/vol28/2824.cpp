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
    int t,d,l;
    while(cin >>t >>d >>l,t){
        vector<int> s(t);
        rep(i,t){
            int x;
            cin >>x;
            if(x>=l){
                s[i]++;
                s[min(t-1,i+d)]--;
            }
        }
        rep(i,t-1) s[i+1] += s[i];

        int ans = 0;
        rep(i,t) ans += (s[i]>0);
        cout << ans << endl;
    }
    return 0;
}
