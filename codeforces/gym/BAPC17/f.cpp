#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0; (i)<(int)n; ++(i))
#define all(x) (x).begin(), (x).end()

int n;
int a[101];

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    int al=0,bo=0;
    int c=0;
    for(int i=n-1;i>=0;i--){
        if(c==0)al+=a[i];
        else bo+=a[i];
        c=1-c;
    }
    printf("%d %d\n",al,bo);
    return 0;
}
