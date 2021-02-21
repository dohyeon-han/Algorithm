#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
//배열 값마다 수행할 수 있는 퀘스트 수 저장,포인트 축적
//포인트를 0부터 최대까지 str int에 나눠 재귀함수 수행
int chk[1001][1001];
bool flag[51] = { false };
int n;

struct S {
	int st, in, pt햣;
};

int calc(S* arr, int st, int in) {
	if (chk[st][in] != -1) {
		return chk[st][in];
	}
	int cnt = 0, pt = 0;
	vector<int> v;

	for (int i = 0; i < n; i++)
	{
		if (arr[i].st <= st || arr[i].in <= in) {
			if (!flag[i]) {
				flag[i] = true;
				pt += arr[i].pt;
				v.push_back(i);
			}
			cnt++;
		}
	}
	chk[st][in] = cnt;
	for (int i = st; i <= min(1000, st + pt); i++)
	{
		chk[st][in] = max(chk[st][in], calc(arr, i, min(1000, in + st + pt - i)));
	}

	for (int i = 0; i < v.size(); i++)
	{
		flag[v[i]] = false;
	}

	return chk[st][in];
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	S arr[51] = {};

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i].st >> arr[i].in >> arr[i].pt;
	}

	memset(chk, -1, sizeof(chk));

	cout << calc(arr, 1, 1);
}