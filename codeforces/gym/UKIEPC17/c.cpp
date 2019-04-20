#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int f(string s){
    if(s[0]=='r') return 1;
    if(s[0]=='y') return 2;
    if(s[0]=='g') return 3;
    if(s[0]=='p') return 6;

    if(s[1]=='r') return 4;
    if(s[2]=='a') return 7;
    return 5;
}

int main(){
    int n;
    cin >>n;

    int red = 0;
    vector<int> ot;
    rep(i,n){
        string s;
        cin >>s;
        int v = f(s);

        if(v==1) ++red;
        else ot.pb(v);
    }

    sort(all(ot));

    int ans = 0;
    int prev = 0;
    while(1) {
        if (red == 0) {
            for (int i:ot) ans += i;
            break;
        }

        if (prev == 0) {
            if (!ot.empty()) {
                int v = ot.back();
                prev = v;
                ans += v;
            } else {
                prev = 1;
                ans += 1;
            }
        } else {
            if (prev == 1) {
                if(ot.empty()) break;

                int v = ot.back();
                prev = v;
                ans += v;
            } else {
                --red;
                prev = 1;
                ans += 1;
            }
        }
    }

    cout << ans << endl;
    return 0;
}