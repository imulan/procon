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
    int zero,one,x;
    cin >>zero >>one >>x;

    int F = (one>zero);

    vector<int> L(x+1,1);
    rep(i,x+1){
        if( (F+i)%2 == 1) --one;
        else --zero;
    }

    if(F){
        rep(i,one) ++L[0];
        rep(i,zero) ++L[1];
    }
    else{
        rep(i,one) ++L[1];
        rep(i,zero) ++L[0];
    }

    rep(i,x+1){
        rep(j,L[i]) cout << (F+i)%2;
    }
    cout << endl;
    return 0;
}
