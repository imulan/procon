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

const int INF = 10101010;

using pi = pair<int,int>;

int main(){
    int n;
    cin >>n;

    int a[2][2];
    rep(i,2)rep(j,2){
        cin >>a[i][j];
        --a[i][j];
    }

    int ans = INF;
    for(int h=1; h<=100; ++h)for(int w=1; w<=100; ++w){
        auto IN = [&](pi p){
            return 0<=p.fi && p.fi<h && 0<=p.se && p.se<w;
        };

        auto GET = [&](int id){
            return pi(id/w, id%w);
        };

        auto DIST = [&](pi p, pi q){
            return abs(p.fi-q.fi) + abs(p.se-q.se);
        };

        auto CALC = [&](){
            rep(i,2)rep(j,2)if(!IN(GET(a[i][j]))) return INF;

            int ret = 0;
            rep(i,2) ret += DIST(GET(a[i][0]), GET(a[i][1]));
            return ret;
        };

        ans = min(ans, CALC());
    }
    cout << ans << endl;
    return 0;
}
