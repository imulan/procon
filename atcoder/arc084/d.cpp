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

const int INF = 19191919;

int main(){
    int k;
    cin >>k;

    vector<int> d(k, INF);
    d[1] = 1;
    queue<int> que({1});
    while(!que.empty()){
        int v = que.front();
        que.pop();

        // +1 or *10
        for(auto e:vector<pair<int,int>>({{v+1,1}, {v*10,0}})){
            int nv = e.fi%k, cost = e.se;
            if(d[nv] > d[v]+cost){
                d[nv] = d[v]+cost;
                que.push(nv);
            }
        }
    }
    cout << d[0] << endl;
    return 0;
}
