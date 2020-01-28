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

const int N = 1000000;
bool c[N];

int main(){
    int q,x;
    scanf(" %d %d", &q, &x);

    vector<int> nx(x);
    rep(i,x) nx[i] = i;

    int mex = 0;
    rep(i,q){
        int y;
        scanf(" %d", &y);
        y%=x;

        if(nx[y] < N){
            c[nx[y]] = true;
            nx[y] += x;
        }

        while(c[mex]) ++mex;
        printf("%d\n", mex);
    }
    return 0;
}
