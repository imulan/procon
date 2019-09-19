#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
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
    int h = stoi(s.substr(0,2));
    int m = stoi(s.substr(3));
    return h*60+m;
}

void PRINT(int x){
    int h = x/60, m = x%60;
    printf("%02d:%02d\n", h,m);
}

int main(){
    int t[2];
    rep(i,2) t[i] = READ();
    PRINT(t[0] + (t[1]-t[0])/2);
    return 0;
}
