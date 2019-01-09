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

int READ(){
    string s;
    cin >>s;
    string t = s[0] + s.substr(2);
    return stoi(t);
}

const int N = 4001;

int main(){
    int n;
    cin >>n;

    vector<int> a(n);
    rep(i,n) a[i] = READ();

    vector<vector<int>> x(N);
    rep(i,n) x[a[i]].pb(i);

    int ct = 0;
    vector<int> ans(n);
    rep(i,N){
        int p = x[i].size();
        for(int j:x[i]) ans[j] = ct*3 + p - 1;
        ct += p;
    }
    rep(i,n) cout << ans[i] << "\n";
    return 0;
}
