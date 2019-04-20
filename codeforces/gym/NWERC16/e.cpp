#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

using pi = pair<int,int>;

int main(){
    int n;
    cin >>n;

    vector<pi> s(n);
    rep(i,n){
        cin >>s[i].fi;
        s[i].se = i;
    }
    sort(all(s));
    reverse(all(s));

    queue<int> que;
    rep(i,n){
        if(i>0){
            rep(j,s[i].fi){
                if(que.empty()){
                    cout << "impossible" << endl;
                    return 0;
                }

                int v = que.front();
                que.pop();
                if(v == i){
                    cout << "impossible" << endl;
                    return 0;
                }
            }
        }

        rep(j,s[i].fi) que.push(i);
    }

    rep(j,s[0].fi){
        if(que.empty()){
            cout << "impossible" << endl;
            return 0;
        }

        int v = que.front();
        que.pop();
        if(v == 0){
            cout << "impossible" << endl;
            return 0;
        }
    }

    rep(i,n) cout << s[i].se+1 << " \n"[i==n-1];
    return 0;
}