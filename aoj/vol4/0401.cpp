#include <bits/stdc++.h>
using namespace std;

const int N = 202;
int g[N][N];
int G(int w, int b){
    if(g[w][b]>=0) return g[w][b];

    bool a[N]={};
    if(w>0) a[G(w-1,b)] = true;
    for(int i=1; i<=min(w,b); ++i) a[G(w,b-i)] = true;
    if(b>0) a[G(w+1,b-1)] = true;

    int ret = 0;
    while(a[ret]) ++ret;
    return g[w][b] = ret;
}

int main(){
    memset(g,-1,sizeof(g));
    int n;
    cin >>n;
    int a = 0;
    while(n--){
        int w,b;
        cin >>w >>b;
        a ^= G(w,b);
    }
    cout << !a << endl;
    return 0;
}
