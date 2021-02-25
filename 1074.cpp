#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n, r, c, rst = 0;
	
	cin >> n >> r >> c;
	
	int x = pow(2, n - 1);
	int y = pow(2, n - 1);
	//1 2
	//3 4

	while (n-->0) {
		int next = pow(2, n - 1);
		if (x > c && y > r) {//1
			x -= next;
			y -= next;
		}
		else if (x <= c && y > r) {//2
			x += next;
			y -= next;
			rst += pow(4, n);
		}
		else if (x > c && y <= r) {//3
			x -= next;
			y += next;
			rst += pow(4, n) * 2;
		}
		else {//4
			x += next;
			y += next;
			rst += pow(4, n) * 3;
		}
	}
	cout << rst;
}