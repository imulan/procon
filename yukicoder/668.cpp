#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

int main(){
    string s;
    cin >>s;

    if(s[2]-'0'>4){
        if(s[1]=='9'){
            s[1] = '0';
            if(s[0]=='9'){
                s[0] = '0';
                s = "1"+s;
            }
            else ++s[0];
        }
        else ++s[1];
    }

    int a = s[0]-'0', b = s[1]-'0';
    int c = s.size()-1;
    printf("%d.%d*10^%d\n", a, b, c);
    return 0;
}
