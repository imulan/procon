#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0; i<(int)n; ++i)
#define all(x) (x).begin() (x).end();

int main()
{
    long s,t,d;
    cin>>s>>t>>d;

    vector<long> vec(d);
    rep(i,d) cin>>vec[i];

    long hoge=0;
    long down=0;
    rep(i,d){
        hoge += vec[i];
        down = min(down, hoge);
        if(s + hoge <= t) {
            cout << i+1 << endl;
            return 0;
        }
    }

    if(hoge >= 0){
        cout << -1 << endl;
        return 0;
    }

    long syuki = max(0L,-(s-t+down)/hoge);

    // cout << hoge << endl;
    // cout << syuki << endl;

    s += hoge * syuki;

    long ans = syuki*d;

    if(s <= t){
        cout << ans << endl;
        return 0;
    }

    for(int i=0; ; i++){
        s += vec[i%d];
        if(s <= t){
            cout << ans + i + 1 << endl;
            return 0;
        }
    }
    assert(false);
}
