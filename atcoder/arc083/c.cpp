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

using pi = pair<int,int>;

const int N = 3030;
bool sugar[N];

bool g(pi p, pi q){
    int pa = p.se, pb = p.fi;
    int qa = q.se, qb = q.fi;
    return pa*qb > qa*pb;
}

bool melt(int e, int s, int w){
    return e*w >= s*100;
}

int main(){
    int a,b,c,d,e,f;
    cin >>a >>b >>c >>d >>e >>f;

    sugar[0] = true;
    rep(i,N)if(sugar[i]){
        sugar[min(N-1,i+c)] = true;
        sugar[min(N-1,i+d)] = true;
    }

    pi ans(100*a,0);
    rep(i,31)rep(j,31)if(i+j>0){
        int water = 100*(i*a+j*b);
        if(water>f) continue;
        rep(k,N)if(sugar[k]){
            if(water+k>f) continue;
            if(!melt(e,k,water)) continue;

            pi t(water+k, k);
            if(g(t,ans)) ans = t;
        }
    }

    cout << ans.fi << " " << ans.se << endl;
    return 0;
}
