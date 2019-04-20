#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int main(){
    string s;
    cin >>s;

    string t = s;
    sort(all(t));

    int n = s.size();
    rep(i,n){
        if(t[i] == s[i]) continue;

        int idx = -1;
        for(int j=i+1; j<n; ++j){
            if(t[j] == s[i]){
                idx = j;
                break;
            }
        }
        assert(idx!=-1);

        int a=idx, b=i;
        if(t[a]<t[b]) swap(a,b);
        printf("%d %d\n",a+1,b+1);
        swap(t[a],t[b]);
    }
    return 0;
}