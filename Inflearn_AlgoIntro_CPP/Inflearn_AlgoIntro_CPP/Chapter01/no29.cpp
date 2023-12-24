#include <iostream>
#include <string>

using namespace std;

int main() {
	int N{}, ans{};
	cin >> N;

	for (int i = 1; i <= N; i++) {
		string str = to_string(i);
		for (int j = 0; j < str.length(); j++) {
			if (str[j] == '3') ans++;
		}
	}

	cout << ans;

	return 0;
}