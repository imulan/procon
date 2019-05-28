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

char M(char a, char b){
    if(a=='T' && b=='F') return 'F';
    return 'T';
}

int main(){
    int n;
    cin >>n;
    vector<char> p(n);
    rep(i,n) cin >>p[i];

    char c = M(p[0], p[1]);
    for(int i=2; i<n; ++i) c = M(c,p[i]);
    cout << c << endl;
    return 0;
}
