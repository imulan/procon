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
    int n,m;
    cin >>n >>m;

    vector<int> w(n);
    int x = 0, y = 0;
    rep(i,m){
        int p;
        string s;
        cin >>p >>s;
        --p;
        if(w[p]==-1) continue;

        if(s=="WA"){
            ++w[p];
        }
        else{
            ++x;
            y += w[p];
            w[p] = -1;
        }
    }

    cout << x << " " << y << "\n";
    return 0;
}
