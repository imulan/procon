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
    int h,w;
    while(cin >>h >>w,h){
        vector<vector<int>> e(h,vector<int>(w));
        rep(i,h)rep(j,w) cin >>e[i][j];

        int ans = 0;
        rep(li,h)rep(lj,w)for(int ri=li+2; ri<h; ++ri)for(int rj=lj+2; rj<w; ++rj){

            int out = 9, in = 0;
            for(int y=li; y<=ri; ++y)for(int x=lj; x<=rj; ++x){
                if(y==li || y==ri || x==lj || x==rj){
                    out = min(out, e[y][x]);
                }
                else{
                    in = max(in, e[y][x]);
                }
            }

            if(out<=in) continue;
            int tmp = 0;
            for(int y=li+1; y<ri; ++y)for(int x=lj+1; x<rj; ++x) tmp += out - e[y][x];
            ans = max(ans, tmp);
        }
        cout << ans << endl;
    }
    return 0;
}
