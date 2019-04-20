#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const vector<string> NG(1,"impossible");

vector<string> solve(){
    int h,w;
    cin >>h >>w;
    vector<vector<int>> a(h+2, vector<int>(w+2));
    rep(i,h+2)rep(j,w+2) cin >>a[i][j];

    vector<string> s(h, string(w,'.'));
    rep(i,h)rep(j,w){
        if(a[i][j]>0){
            s[i][j] = 'X';
            rep(y,3)rep(x,3) --a[i+y][j+x];
        }
    }

    rep(i,h+2)rep(j,w+2)if(a[i][j] != 0) return NG;
    return s;
}

int main(){
    for(string s:solve()) cout << s << "\n";
    return 0;
}

