#include <iostream>
#include <stack>
#include <string>
using namespace std;

// n%3==2 이면 (n+1)/3
// n%3==1 이면 (n-1)/3
// n이 음수이면 1과 2(T)를 바꿔 출력

int n;
stack<int> st;
bool isNeg = false;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;
	if (n == 0) {
		cout << "0";
		return 0;
	}
	if (n < 0) {
		isNeg = true;
		n = -n;
	}
	while (n) {
		st.push(n % 3);
		if (st.top() == 1) n--;
		else if (st.top() == 2) n++;
		n /= 3;
	}
	while (!st.empty()) {
		if (!isNeg) 
			cout << (st.top() == 2 ? "T" : to_string(st.top()));
		else {
			if (st.top() == 2) cout << 1;
			else if (st.top() == 1) cout << 'T';
			else cout << 0;
		}
		st.pop();
	}
}