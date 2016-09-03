#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <utility>
using namespace std;

int main(){
	int a[3];
	scanf(" %d %d %d", &a[0], &a[1], &a[2]);
	sort(a, a+3);
	printf("%d\n", a[1]);
}