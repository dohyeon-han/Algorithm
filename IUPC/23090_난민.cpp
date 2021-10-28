#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

//y좌표들 중 중앙값이 우물을 놓아야할 자리
//sum += 중앙값을 제외한 두 큐의 개수의 차(1 or 0)*이전 중앙값과의 차 
// + 새 난민촌과의 거리를

priority_queue<int> l,s;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	long long n, x, y, prevY, nowY, sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;

		if (s.empty()) {
			s.push(y);
			prevY = y;
		}
		else {
			if (s.top() < y) 
				l.push(-y);
			else
				s.push(y);
		}

		if (s.size() < l.size()) {
			s.push(-l.top());
			l.pop();
		}
		else if(l.size() + 1 < s.size()){
			l.push(-s.top());
			s.pop();
		}
		nowY = s.top();

		if (i == 0) sum = abs(x);
		else
			sum += abs(x) + abs(prevY - nowY) * abs((int)(l.size() - s.size() + 1)) + abs(nowY - y);

		cout << (prevY = nowY) << ' ' << sum << '\n';
	}
}