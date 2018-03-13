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
    int Q,K;
    scanf(" %d %d", &Q, &K);

    priority_queue<ll> small;
    priority_queue<ll, vector<ll>, greater<ll>> large;

    while(Q--){
        int q;
        scanf(" %d", &q);
        if(q==1){
            ll v;
            scanf(" %lld", &v);
            if(small.size()<K) small.push(v);
            else{
                if(small.top()>v){
                    large.push(small.top());
                    small.pop();
                    small.push(v);
                }
                else large.push(v);
            }
        }
        else{
            ll ans = -1;
            if(small.size() == K){
                ans = small.top();
                small.pop();
                if(!large.empty()){
                    small.push(large.top());
                    large.pop();
                }
            }
            printf("%lld\n", ans);
        }
    }

    return 0;
}
