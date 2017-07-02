#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);i++)

int main() {
    int t,d,l;
    while(cin >>t >>d >>l, t)
    {
        vector<int> vec(t);
        rep(i,t) cin>>vec[i];

        int ans = 0;
        int left = 0;
        rep(i,t){
            if(left>0) ans++;
            if(vec[i]>=l) left = d;
            else left--;
        }
        cout << ans << endl;
    }
    return 0;
}
