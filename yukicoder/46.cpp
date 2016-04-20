#include <cstdio>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
  int a,b;
  cin >>a >>b;

  int ans=b/a;
  if(b%a!=0) ++ans;

  std::cout << ans << std::endl;

  return 0;
}
