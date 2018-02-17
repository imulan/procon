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

int solve(const string &s){
    int n = s.size();
    if(n%2 == 1) return -1;

    int ct[400] = {};
    rep(i,n) ++ct[s[i]];

    int ans = n;
    rep(i,n+1){
        if(2*i>n) break;

        int t = 0;
        // 'R' i回, 'L' i回
        if(ct['R']>i) t += ct['R']-i;
        if(ct['L']>i) t += ct['L']-i;

        int r = n - 2*i;
        r /= 2;
        // 'U' r回, 'D r回
        if(ct['U']>r) t += ct['U']-r;
        if(ct['D']>r) t += ct['D']-r;

        ans = min(ans,t);
    }
    return ans;
}

int main(){
    string s;
    cin >>s;
    cout << solve(s) << endl;
    return 0;
}
