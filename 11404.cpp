#include <iostream>
using namespace std;

#define INF 987654321

//플로이드 워셜
//middle - from - to 순서
//from - to - middle 일 경우 125 135 145 처럼 1->5의 경로 계산을 한 사이클에 해버려서 1245와 같은 경로 계산이 안됨

int rst[101][101];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int city, bus;
	cin >> city >> bus;
	
	for (int i = 1; i <= city; i++)
	{
		for (int j = 1; j <= city ; j++)
		{
			rst[i][j] = INF;
		}
	}

	for (int i = 0; i < bus; i++)
	{
		int a, b, t;
		cin >> a >> b >> t;
		rst[a][b] = min(t,rst[a][b]);
	}
	
	for (int i = 1; i <= city; i++)//중간
	{
		for (int j = 1; j <= city; j++)//끝
		{
			if (i == j) continue;
			for (int k = 1; k <= city; k++)//처음
			{
				if (k == i || k == j) continue;
				if (rst[j][i] + rst[i][k] < rst[j][k]) {
					rst[j][k] = rst[j][i] + rst[i][k];
				}
			}
		}
	}

	for (int i = 1; i <= city; i++)
	{
		for (int j = 1; j <= city; j++)
		{
			if (i == j||rst[i][j]==INF) {//a->a 또는 갈 수 없는 곳
				cout << "0 ";
			}
			else cout << rst[i][j] << ' ';
		}
		cout << '\n';
	}
}