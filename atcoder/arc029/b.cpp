#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(i=0;i<n;++i)
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define mp make_pair
#define pb push_back
#define fi first
#define sc second

double eps=1e-6;

int main(int argc, char const *argv[]) {
  int i;

  double a,b;
  cin >>a >>b;

  a/=100;
  b/=100;

  int n;
  cin >>n;
  rep(i,n){
    double c,d;
    scanf(" %lf %lf",&c,&d);
    if(c>d) swap(c,d);

    c/=100;
    d/=100;

    bool valid=true;

    /*
    double base=M_PI/2-atan2(d,c);
    base*=180/M_PI;

    double st=base-10;
    if(st<0) st=0;

    double ed=base+10;
    if(ed>90)ed=90;
    */
    for(double angle=0; angle<=90; angle+=0.05){
      double t=angle*M_PI/180;

      valid=true;
      if(a*cos(t)>c) valid=false;
      if(a*sin(t)>d) valid=false;
      if(b*sin(t)>c) valid=false;
      if(b*cos(t)+a*sin(t)>d) valid=false;
      if(a*cos(t)+b*sin(t)>c) valid=false;
      if(b*cos(t)>d) valid=false;
      if(valid) break;

      valid=true;
      if(b*cos(t)>c) valid=false;
      if(b*sin(t)>d) valid=false;
      if(a*sin(t)>c) valid=false;
      if(a*cos(t)+b*sin(t)>d) valid=false;
      if(b*cos(t)+a*sin(t)>c) valid=false;
      if(a*cos(t)>d) valid=false;

      if(valid) break;
    }

    string ans="NO";
    if(valid) ans="YES";
    std::cout << ans << std::endl;
  }
  return 0;
}
