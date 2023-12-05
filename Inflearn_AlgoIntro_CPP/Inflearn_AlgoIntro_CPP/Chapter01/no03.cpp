#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int N{}, sum{};

	vector<int> v;

	cin >> N;

	for (int i = 1; i <= sqrt(N); i++) {
		if (N % i == 0) {
			v.push_back(i); // ���
			if(N / i != i && N / i != N) 
				v.push_back(N / i); // ��� ¦��
		}
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		sum += v[i];
		cout << v[i];
		if (i < v.size() - 1) cout << " + ";
	}

	cout << " = " << sum;
	return 0;
}
