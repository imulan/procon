#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int main()
{
    int n,m,k;
    cin >>n >>m >>k;

    char c='L';
    if(k%2==0) c='R';

    int lane = (k-1)/(2*m);
    int desk = ((k-1)%(2*m))/2;

    printf("%d %d %c\n", lane+1, desk+1, c);
    return 0;
}
