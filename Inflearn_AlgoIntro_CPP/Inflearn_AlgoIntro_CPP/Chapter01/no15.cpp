#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N{}, res{};
	cin >> N;
	vector<int> v(N+1); // 0 ��Ž��, 1 �Ҽ�, 2 �Ҽ�x

	for (int i = 2; i <= N; i++) {
		if (v[i] != 0) continue;
		
		v[i] = 1;
		res++;
		for (int j = i + i; j <= N; j += i) {
			if(v[j] == 0) v[j] = 2;
		}
	}


	cout << res;

	return 0;
}