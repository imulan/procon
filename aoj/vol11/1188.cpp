#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
  int n;
  cin >> n;
  for(int times=0; times<n; ++times){
    string s;
    cin >> s;

    int L=0, R=0;
    int k=0;
    //文字列を走査していく
    for(int i=0; i<s.size(); ++i){
      if(s[i]=='[') L++;
      else if(s[i]==']') R++;
      k=max(k,(L-R));
    }

    vector< vector<int> > q(5000);

    L=0, R=0;
    //文字列を走査していく
    for(int i=0; i<s.size(); ++i){
      if(s[i]=='[') L++;
      else if(s[i]==']'){
        R++;
        if(q[L-R+2].size()!=0){
          sort(q[L-R+2].begin(), q[L-R+2].end());

          int ins=0;
          for(int i=0; i<=q[L-R+2].size()/2; ++i){
            if(L-R+2==k) ins+=q[L-R+2][i]/2+1;
            else ins+=q[L-R+2][i];
          }
          //printf("dep = %d,ins = %d\n", L-R+1, ins);
          q[L-R+2].resize(0);
          q[L-R+1].push_back(ins);
        }
      }
      else{ //数字
        int st=i;
        while(s[i+1]!=']') i++;
        //string tmp = s.substr(st,i-st+1);
        q[L-R].push_back(atoi(s.substr(st,i-st+1).c_str()));

      }
    }

    cout << q[1].front() <<endl;
  }
}
