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

const int INF = 19191919;

int main(){
    int n,k;
    cin >>n >>k;

    vector<int> d(1<<k,INF);
    queue<int> que;

    rep(i,n){
        string s;
        cin >>s;

        int a = 0;
        rep(j,k)if(s[j]=='1') a |= (1<<j);

        d[a] = 0;
        que.push(a);
    }

    while(!que.empty()){
        int v = que.front();
        que.pop();
        rep(i,k){
            int nx = v^(1<<i);
            if(d[nx] > d[v]+1){
                d[nx] = d[v]+1;
                que.push(nx);
            }
        }
    }

    int max_d = 0;
    int ans = 0;
    rep(i,1<<k){
        if(max_d < d[i]){
            max_d = d[i];
            ans = i;
        }
    }

    rep(i,k) cout << (ans>>i&1);
    cout << '\n';
    return 0;
}
