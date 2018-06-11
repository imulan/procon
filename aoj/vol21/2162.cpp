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

int lcm(int x, int y){
    return x/__gcd(x,y)*y;
}

int main(){
    set<int> bp;
    for(int i:{13,17,19,23}) bp.insert(i);

    int a = 1, b = 1;
    for(int i=1; i<=24; ++i){
        if(bp.count(i)) b = lcm(b,i);
        else a = lcm(a,i);
    }

    int n;
    while(cin >>n,n){
        vector<int> A(a), B(b);

        rep(i,n){
            int d,t;
            cin >>d >>t;

            vector<int> x(d);
            rep(j,d) cin >>x[j];

            if(bp.count(d)){
                rep(j,b) B[j] += x[(j+t)%d];
            }
            else{
                rep(j,a) A[j] += x[(j+t)%d];
            }
        }

        int maxA = 0, maxB = 0;
        rep(i,a) maxA = max(maxA, A[i]);
        rep(i,b) maxB = max(maxB, B[i]);
        cout << maxA+maxB << endl;
    }

    return 0;
}
