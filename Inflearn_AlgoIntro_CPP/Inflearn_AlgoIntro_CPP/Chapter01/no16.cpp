#include <iostream>

using namespace std;

int main() {
	string str1{}, str2{};

	cin >> str1 >> str2;

	// A~Z(65~90), a~z(97~122)
	// 65~122 : 122-65 + 1 = 58
	int arr1[58]{};
	int arr2[58]{};

	bool isAnagram = true;
	if (str1.length() != str2.length()) {
		isAnagram = false;
	}
	else {
		for (int i = 0; i < str1.length(); i++) {
			arr1[str1[i] - 'A']++;
			arr2[str2[i] - 'A']++;
		}

		for (int i = 0; i < sizeof(arr1)/sizeof(int); i++) {
			if (arr1[i] != arr2[i]) {
				isAnagram = false;
				break;
			}
		}
	}

	if (isAnagram) cout << "YES";
	else cout << "NO";
	return 0;
}