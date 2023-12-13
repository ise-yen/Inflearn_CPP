#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
int ans{};
void sumSubset(int x, int N, int sum, int M) {
	if (x == N) {
		if (sum == M) {
			ans++;
		}
		return;
	}

	sumSubset(x + 1, N, sum + v[x], M);
	sumSubset(x + 1, N, sum, M);
	sumSubset(x + 1, N, sum - v[x], M);
}

int main() {
	int N{}, M{};
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int tmp{};
		cin >> tmp;
		v.push_back(tmp);
	}

	sumSubset(0, N, 0, M);

	if (ans == 0) cout << -1;
	else cout << ans;
	return 0;
}