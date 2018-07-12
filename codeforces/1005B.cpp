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
    string s,t;
    cin >>s >>t;
    int S = s.size(), T = t.size();

    int L=0;
    while(1){
        int i = S-1-L, j = T-1-L;
        if(i<0 || j<0) break;
        if(s[i]!=t[j]) break;
        ++L;
    }

    cout << S+T-2*L << endl;
    return 0;
}
