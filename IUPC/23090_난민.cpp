#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

//y��ǥ�� �� �߾Ӱ��� �칰�� ���ƾ��� �ڸ�
//sum += �߾Ӱ��� ������ �� ť�� ������ ��(1 or 0)*���� �߾Ӱ����� �� 
// + �� �����̰��� �Ÿ���

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