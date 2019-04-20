#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int main(){
    int n;
    cin >>n;

    vector<int> h(n),r(n),t(n);
    int mh = 0;
    rep(i,n){
        cin >>h[i] >>r[i] >>t[i];
        mh = max(mh,h[i]);
    }

    int V = 1825*mh;
    vector<int> v(V);

    rep(i,n){
        int s = r[i];
        int e = t[i];

        if(r[i] > t[i]){
            rep(j,t[i]) ++v[j];
            e += h[i];
        }

        while(s<V){
            for(int j=s+1; j<e; ++j){
                if(j<V) ++v[j];
            }
            s += h[i];
            e += h[i];
        }
    }

    rep(i,V){
        if(v[i]==0){
            cout << i << '\n';
            return 0;
        }
    }
    cout << "impossible" << '\n';
    return 0;
}