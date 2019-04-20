#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define pb push_back

#define l first
#define r second

using pi = pair<int,int>;

int main(){
    int n,Q;
    cin >>n >>Q;

    vector<int> x(n);
    rep(i,n) cin >>x[i];

    int H = n+1, T = n+2;
    vector<pi> a(n+3);

    a[H].r = x[0];
    a[x[0]].l = H;
    for(int i=1; i<n; ++i){
        a[x[i-1]].r = x[i];
        a[x[i]].l = x[i-1];
    }
    a[x[n-1]].r = T;
    a[T].l = x[n-1];

    if(n==1){
        int q;
        rep(i,Q) cin >>q;
        cout << 1 << endl;
        return 0;
    }

    while(Q--){
        int q;
        cin >>q;

        int HR = a[H].r;
        int TL = a[T].l;
        int L = a[q].l;
        int R = a[q].r;

        // printf(" HR L R TL %d %d %d %d\n", HR,L,R,TL);

        if(L==H){
            a[H].r = R;
            a[R].l = H;

            a[TL].r = q;
            a[q].l = TL;

            a[q].r = T;
            a[T].l = q;
        }
        else if(R==T){
            a[H].r = q;
            a[q].l = H;

            a[q].r = HR;
            a[HR].l = q;

            a[L].r = T;
            a[T].l = L;
        }
        else{
            a[H].r = R;
            a[R].l = H;

            a[TL].r = q;
            a[q].l = TL;

            a[q].r = HR;
            a[HR].l = q;

            a[L].r = T;
            a[T].l = L;
        }

        // int now = H;
        // rep(i,n){
        //     now = a[now].r;
        //     cout << now << " \n"[i==n-1];
        // }
    }

    int now = H;
    rep(i,n){
        now = a[now].r;
        cout << now << " \n"[i==n-1];
    }

    return 0;
}
