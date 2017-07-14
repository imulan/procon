#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define pb(a) push_back((a))

vector<string> split(string &str){
    vector<string> v;
    stringstream ss(str);
    string bu;
    while( getline(ss, bu, '"') ) v.pb(bu);
    return v;
}

int solve(vector<string> &v1, vector<string> &v2){
    int d =0;
    if(v1.size() != v2.size()) return 2;

    int n = v1.size();
    rep(i,n){
        if(v1[i] != v2[i]){
            if(i%2==0) return 2;
            else {
                d++;
                if(d>=2) return 2;
            }
        }
    }
    if(d==1)return 1;
    return 0;
}

int main(){
    string s,t;
    while(cin>>s, s!="."){
        cin>>t;
        auto v1 = split(s), v2 = split(t);
        int r = solve(v1,v2);
        if(r == 0){
            cout << "IDENTICAL" << endl;
        }
        else if(r==1){
            cout << "CLOSE" << endl;
        } else {
            cout << "DIFFERENT" << endl;
        }
    }


    return 0;
}
