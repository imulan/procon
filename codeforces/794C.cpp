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
    string a,b;
    cin >>a >>b;
    int n = a.size();

    sort(all(a));
    sort(all(b));
    reverse(all(b));

    a.resize((n+1)/2);
    b.resize(n/2);

    string ans(n,'?');
    int h=0, t=n-1;

    int x = 0, y = 0;
    bool ta = true;
    bool backa = false, backb = false;

    rep(_,n){
        if(ta){
            if(!backa){
                if(a[x]<b[y]) ans[h++] = a[x++];
                else{
                    backa = true;
                    x = a.size()-1;
                }
            }

            if(backa) ans[t--] = a[x--];
        }
        else{
            if(!backb){
                if(b[y]>a[x]) ans[h++] = b[y++];
                else{
                    backb = true;
                    y = b.size()-1;
                }
            }

            if(backb) ans[t--] = b[y--];
        }
        ta = !ta;
        // dbg(ans);
    }

    rep(i,n) assert(ans[i]!='?');
    cout << ans << endl;
    return 0;
}
