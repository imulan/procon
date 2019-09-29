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

int main(){
    int n,a,b;
    cin >>n >>b >>a;
    vector<int> s(n);
    rep(i,n) cin >>s[i];

    const int capA = a;

    int x = 0;
    while(x<n && (a>0||b>0)){
        if(s[x]){
            if(b>0 && a<capA){
                --b;
                ++a;
            }
            else --a;
        }
        else{
            if(a>0) --a;
            else --b;
        }
        ++x;
    }
    cout << x << "\n";
    return 0;
}
