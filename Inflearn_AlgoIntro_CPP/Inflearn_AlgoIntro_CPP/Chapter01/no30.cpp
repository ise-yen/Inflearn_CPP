#include <iostream>
#include <algorithm>

using namespace std;

void answer() {
	int N{}, ans{};
	cin >> N;

	/*
	0 0 0 1
	0 0 0 2
	0 0 0 3
	... 
	... 
	0 0 3 0
	0 0 3 1
	0 0 3 2
	0 0 3 3
	... 
	0 1 3 0
	0 1 3 1
	0 1 3 2
	0 1 3 3
	... 
	... 
	0 3 0 0
	0 3 0 1
	0 3 0 2
	... 
	... 
	*/

	// 자릿수마다 3 여부 판단

	// 현재 자리의 숫자, cur의 왼쪽 숫자, 오른쪽 숫자
	int cur{}, left = 1, right{};
	int k = 1; // 자리수

	while (left > 0) {
		left = N / (k * 10);
		cur = (N/k) % 10;
		right = N % k;
		if (cur < 3) ans += left * k;
		else if (cur == 3) {
			ans += (left)*k + right + 1; // +1인 이유 : 0일 때 포함해야해서
		}
		else ans += (left + 1) * k;
		k *= 10;
	}

	cout << ans;
}

int main() {
	answer();
	return 0;
}