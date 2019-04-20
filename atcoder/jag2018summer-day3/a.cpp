#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back

int main(){
    string s;
    cin >>s;
    int n = s.size();

    int ans = 0;
    int start = 0;
    while(start<n){
        int dir = 0;
        int i = start;
        int flg[4]={};
        while(i<n){
            if(s[i]=='R'){
                (dir += 1) %= 4;
                flg[dir] = 1;
            }
            else{
                (dir += 3) %= 4;
            }
            ++i;

            if(dir==0) break;
        }

        int ok = 1;
        rep(j,4) ok &= flg[j];
        ans += ok;
        start = i;
    }

    cout << ans << endl;
    return 0;
}
