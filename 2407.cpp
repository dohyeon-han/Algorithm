#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

//결과가 unsigned long long을 넘어버림->string으로 계산, 하나씩 pop하여 더함
//phython으로 하면 쉽다는데..?

string arr[101][101];

string addString(string a, string b) {//한자리씩 pop 하여 계산
	int num = 0;
	string rst;
	while (!a.empty()||!b.empty()||num) {//string이 비고, num계산이 끝나 0이 될 때까지
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
	//if (arr[n][m] != "") {//위와 같은 식
	//	return arr[n][m];
	//}
	//if(n==m||m==0){
	//	return arr[n][m] = "1";
	//}
	//return arr[n][m] = addString(culc(n - 1,m), culc(n - 1,m-1));//파스칼의 삼각형 nCm = nCm-1 + n-1Cm-1
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	cout << culc(n, m);

}