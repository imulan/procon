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
    int n,k;
    cin >>n >>k;

    priority_queue<int> pq;
    int ct = 0;
    rep(i,30){
        if(n>>i&1){
            ++ct;
            pq.push(1<<i);
        }
    }

    if(ct > k || k > n){
        cout << "NO" << "\n";
        return 0;
    }

    while(ct<k){
        int v = pq.top();
        pq.pop();
        rep(i,2) pq.push(v/2);
        ++ct;
    }

    cout << "YES" << "\n";
    while(1){
        cout << pq.top();
        pq.pop();
        if(pq.empty()) break;
        cout << " ";
    }
    cout << "\n";
    return 0;
}
