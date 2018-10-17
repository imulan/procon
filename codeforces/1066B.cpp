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

int solve(){
    int n,r;
    cin >>n >>r;
    vector<int> a(n);
    rep(i,n) cin >>a[i];

    vector<bool> warm(n);
    int ans = 0;
    rep(i,n)if(!warm[i]){
        // pos - r + 1 = i;
        int pos = min(i+r-1, n-1);
        int s = pos;
        while(s>=0){
            if(a[s]) break;
            --s;
        }
        if(s==-1) return -1;

        int L = max(0,s-r+1);
        int R = min(n-1, s+r-1);
        for(int j=L; j<=R; ++j) warm[j] = true;

        if(!warm[i]) return -1;

        ++ans;
    }
    return ans;
}

int main(){
    cout << solve() << endl;
    return 0;
}
