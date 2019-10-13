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

int main(){
    int n,k;
    cin >>n >>k;

    set<int> disp;
    queue<int> que;
    rep(i,n){
        int a;
        cin >>a;

        if(!disp.count(a)){
            disp.insert(a);
            if(que.size() == k){
                disp.erase(que.front());
                que.pop();
            }
            que.push(a);
        }
    }

    vector<int> v;
    while(!que.empty()){
        v.pb(que.front());
        que.pop();
    }
    reverse(all(v));

    int V = v.size();
    cout << V << "\n";
    rep(i,V) cout << v[i] << " \n"[i==V-1];
    return 0;
}
