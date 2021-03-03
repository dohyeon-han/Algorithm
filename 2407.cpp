#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

//����� unsigned long long�� �Ѿ����->string���� ���, �ϳ��� pop�Ͽ� ����
//phython���� �ϸ� ���ٴµ�..?

string arr[101][101];

string addString(string a, string b) {//���ڸ��� pop �Ͽ� ���
	int num = 0;
	string rst;
	while (!a.empty()||!b.empty()||num) {//string�� ���, num����� ���� 0�� �� ������
		if (!a.empty()) {
			num += a.back() - '0';
			a.pop_back();
		}
		if (!b.empty()) {
			num += b.back() - '0';
			b.pop_back();
		}
		char s = (num%10) + '0';
		rst.push_back(s);

		num /= 10;
	}
	reverse(rst.begin(), rst.end());
	return rst;
}

string culc(int n, int m) {
	return arr[n][m] != "" ? arr[n][m] : (n == m || m == 0 ? arr[n][m] = "1" : arr[n][m] = addString(culc(n - 1, m), culc(n - 1, m - 1)));
	//if (arr[n][m] != "") {//���� ���� ��
	//	return arr[n][m];
	//}
	//if(n==m||m==0){
	//	return arr[n][m] = "1";
	//}
	//return arr[n][m] = addString(culc(n - 1,m), culc(n - 1,m-1));//�Ľ�Į�� �ﰢ�� nCm = nCm-1 + n-1Cm-1
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	cout << culc(n, m);

}