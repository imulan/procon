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

int star(int r){
    if(r<=10) return 5;
    if(r<=15) return 4;
    if(r<=20) return 3;
    return 2;
}

int main(){
    string l;
    cin >>l;

    int r = 25, s = 0, c = 0;
    for(char i:l){
        // printf(" %d %d %d\n",r,s,c);
        if(i=='W'){
            ++c;
            ++s;
            if(r>=6 && c>=3) ++s;

            if(star(r)<s){
                s -= star(r);
                --r;
            }
        }
        else{
            c = 0;
            if(r<=20) --s;
            if(r == 20) s = max(s,0);

            if(s<0){
                ++r;
                s = star(r)-1;
            }
        }

        if(r==0){
            cout << "Legend" << endl;
            return 0;
        }
    }
    cout << r << endl;
    return 0;
}
