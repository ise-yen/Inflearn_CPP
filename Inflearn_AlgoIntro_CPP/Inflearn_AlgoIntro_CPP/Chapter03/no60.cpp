#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
vector<bool> isVisit;
bool isSame = false;

void answer(int L, int sum, int N, int total) {
	if (isSame) return;
	if (L == N) {
		if (sum == total - sum) {
			isSame = true;
		}
	}
	else {
		answer(L + 1, sum + v[L], N, total);
		answer(L + 1, sum, N, total);
	}
}

void subset(int x, int N) {
	if (x >= N) {
		int sum1{}, sum2{};
		for (int i = 0; i < N; i++) {
			if (isVisit[i]) sum1 += v[i];
			else sum2 += v[i];
		}

		if (sum1 == sum2) isSame = true;
		return;
	}

	isVisit[x] = true;
	subset(x + 1, N);
	
	isVisit[x] = false;
	subset(x + 1, N);
}

int main() {
	int N{}, total{};
	cin >> N;
	isVisit.resize(N, false);

	for (int i = 0; i < N; i++) {
		int tmp{};
		cin >> tmp;
		v.push_back(tmp);
		total += tmp;
	}

	//subset(0, N);
	answer(0, 0, N, total);

	if (isSame) cout << "YES";
	else cout << "NO";
}