#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

int main(){
    int n;
    cin >>n;
    vector<int> a(n);
    rep(i,n) cin >>a[i];

    int prev = -1;
    int l = 0, r = n-1;
    string s = "";
    while(l<=r){
        if(a[l] < a[r]){
            if(prev < a[l]){
                s += 'L';
                prev = a[l];
                ++l;
            }
            else if(prev < a[r]){
                s += 'R';
                prev = a[r];
                --r;
            }
            else break;
        }
        else if(a[r] < a[l]){
            if(prev < a[r]){
                s += 'R';
                prev = a[r];
                --r;
            }
            else if(prev < a[l]){
                s += 'L';
                prev = a[l];
                ++l;
            }
            else break;
        }
        else{
            int tl = l;
            while(tl<n){
                if(tl==0 || a[tl-1] < a[tl]) ++tl;
                else break;
            }

            int tr = r;
            while(tl>=0){
                if(tr==n-1 || a[tr+1] < a[tr]) --tr;
                else break;
            }

            if(tl-l > r-tr){
                if(prev < a[l]){
                    s += 'L';
                    prev = a[l];
                    ++l;
                }
                else break;
            }
            else{
                if(prev < a[r]){
                    s += 'R';
                    prev = a[r];
                    --r;
                }
                else break;
            }
        }
    }

    cout << s.size() << "\n";
    cout << s << "\n";
    return 0;
}
