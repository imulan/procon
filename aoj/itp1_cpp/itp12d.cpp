#include <iostream>
using namespace std;

int main(){
	int w, h, x, y, r;
	cin >> w >> h >> x >> y >> r;

	if(x>=r && y>=r && w-x>=r && h-y>=r) cout << "Yes" << endl;
	else cout << "No" << endl;
}