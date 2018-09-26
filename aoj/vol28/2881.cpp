#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    while(cin >>s, s!="#"){
        int y,m,d;
        cin >>y >>m >>d;

        string ans = "HEISEI";
        if(y>31 || (y==31 && m>4)){
            y -= 30;
            ans = "?";
        }

        cout << ans << " " << y << " " << m << " " << d << endl;
    }
    return 0;
}
