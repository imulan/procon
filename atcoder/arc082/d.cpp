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
    int n;
    cin >>n;
    vector<int> p(n);
    rep(i,n){
        cin >>p[i];
        p[i] = (p[i]-1==i);
    }

    int st = 0;
    int ans = 0;
    while(st<n){
        if(p[st]==0) ++st;
        else{
            int i=st;
            while(i<n && p[i]==1) ++i;
            int d=i-st;
            ans += (d+1)/2;
            st=i;
        }
    }
    cout << ans << endl;
    return 0;
}
