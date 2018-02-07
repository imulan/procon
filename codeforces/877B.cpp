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

const int N = 5005;
int a[N]={}, b[N]={};

int main(){
    string s;
    cin >>s;
    int n = s.size();

    rep(i,n){
        if(s[i]=='a') ++a[i+1];
        else ++b[i+1];
    }

    rep(i,N-1){
        a[i+1] += a[i];
        b[i+1] += b[i];
    }

    int ans = 0;
    for(int i=1; i<=n; ++i)for(int j=1; j<=i; ++j){
        int t = 0;
        t += a[j];
        t += b[i]-b[j-1];
        t += a[n]-a[i];
        ans = max(ans,t);
    }
    cout << ans << endl;
    return 0;
}
