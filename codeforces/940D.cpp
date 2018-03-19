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

const int INF = 1000000000;

int main(){
    int n;
    cin >>n;
    vector<int> a(n);
    rep(i,n) cin >>a[i];

    string s;
    cin >>s;

    vector<int> b(n);
    rep(i,s.size()) b[i] = s[i]-'0';

    int l = -INF, r = INF;
    for(int i=4; i<n; ++i){
        int sb = 0;
        for(int j=1; j<=4; ++j) sb += b[i-j];

        int max_a = -INF, min_a = INF;
        rep(j,5){
            max_a = max(max_a, a[i-j]);
            min_a = min(min_a, a[i-j]);
        }

        if(sb==0){
            if(b[i]==1) l = max(l, max_a+1);
            else assert(l<=max_a);
        }
        else if(sb==4){
            if(b[i]==0) r = min(r, min_a-1);
            else assert(r>=min_a);
        }
        else assert(b[i] == b[i-1]);
    }

    cout << l << " " << r << endl;
    return 0;
}
