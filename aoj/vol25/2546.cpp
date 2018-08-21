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
    cin >>h >>w;
    vector<vector<int>> a(h,vector<int>(w));
    rep(i,h)rep(j,w) cin >>a[i][j];

    int ans = 0;
    rep(i,h){
        int tmp = 0;
        rep(j,w+1)rep(lr,2){
            int aaa = 0;
            vector<int> v(a[i]);
            if(lr==0){
                rep(k,j){
                    aaa += v[k];
                    if(k+1<w) v[k+1] = !v[k+1];
                }
                for(int k=w-1; k>=j; --k){
                    aaa += v[k];
                    if(k-1>=0) v[k-1] = !v[k-1];
                }
            }
            else{
                for(int k=w-1; k>=j; --k){
                    aaa += v[k];
                    if(k-1>=0) v[k-1] = !v[k-1];
                }
                rep(k,j){
                    aaa += v[k];
                    if(k+1<w) v[k+1] = !v[k+1];
                }
            }

            tmp = max(tmp, aaa);
        }

        ans += tmp;

        if(i<h-1){
            rep(j,w) a[i+1][j] = !a[i+1][j];
        }
    }

    cout << ans << endl;
    return 0;
}
