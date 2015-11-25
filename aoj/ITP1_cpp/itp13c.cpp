#include <iostream>
using namespace std;

int main(){
	while(1){
		int x, y;
		cin >> x >> y;
		if(x==0 && y==0) break;
		
		if(x>y){
			int tmp = x;
			x = y;
			y = tmp;
		}
		cout << x << " " << y <<endl;
	}
}