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

const int N = 100010;
int n;
ll a[N];


int main(){
    scanf(" %d", &n);
    rep(i,n) scanf(" %lld", &a[i]);

    int Q;
    scanf(" %d", &Q);
    while(Q--){
        int t,l,r,x;
        scanf(" %d %d %d %d", &t, &l ,&r, &x);
        --l;
        --r;

        if(t==1){


        }
        else{


        }
    }
    return 0;
}
