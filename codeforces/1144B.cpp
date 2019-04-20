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
    int n;
    cin >>n;

    vector<int> v[2];
    rep(i,n){
        int a;
        cin >>a;
        v[a%2].pb(a);
    }
    rep(i,2) sort(all(v[i]), greater<int>());

    int ans = INT_MAX;
    rep(i,2){
        queue<int> que[2];
        rep(j,2)for(int k:v[j]) que[j].push(k);

        int idx = i;
        while(!que[idx].empty()){
            que[idx].pop();
            idx ^= 1;
        }

        int t = 0;
        rep(j,2){
            while(!que[j].empty()){
                t += que[j].front();
                que[j].pop();

            }
        }
        ans = min(ans, t);
    }
    cout << ans << endl;
    return 0;
}
