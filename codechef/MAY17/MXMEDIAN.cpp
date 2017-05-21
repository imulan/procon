#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int med(const vector<int> &a)
{
    int A = a.size();
    int B = A/2;
    vector<int> b(B);
    rep(i,B) b[i] = max(a[2*i],a[2*i+1]);

    sort(all(b));
    return b[B/2];
}

int main()
{
    int T;
    scanf(" %d", &T);
    while(T--)
    {
        int n;
        scanf(" %d", &n);

        int A=2*n;
        vector<int> a(A);
        rep(i,A) scanf(" %d", &a[i]);

        sort(all(a));

        vector<int> ans(A);
        rep(i,n)
        {
            ans[2*i] = a[i];
            ans[2*i+1] = a[A-1-i];
        }

        printf("%d\n", med(ans));
        rep(i,A)
        {
            if(i) printf(" ");
            printf("%d", ans[i]);
        }
        printf("\n");
    }
    return 0;
}
