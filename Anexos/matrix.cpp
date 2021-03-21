#include <iostream>
using namespace std;

const int N = 12;

int main() {

	int s[N + 2][N + 2];

	for (int i = 1; i < N + 1; ++i) {
		cin >> s[1][i];
		s[i][0] = (N - s[1][i] + s[1][1]) % N;
		s[i][N + 1] = s[i][0];
		s[0][i] = (N - s[i][0]) % N;
		s[N + 1][i] = s[0][i];
	}

	for (int i = 2; i < N + 1; ++i)
		for (int j = 1; j < N + 1; ++j)
			s[i][j] = (s[1][j] + s[i][0]) % N;

	cout << "\n\\[\\begin{array}{l|";
	for (int i = 0; i < N; ++i)	cout << 'c';
	cout << "|r}\n&";

	for (int i = 1; i < N + 1; ++i)
		cout << "\\text{I}_{" << s[0][i] << "}&";
	cout << "\\\\\n\\hline\n";

	for (int i = 1; i < N + 1; ++i) {
		cout << "\\text{T}_{" << s[i][0] << "}&";

		for (int j = 1; j < N + 1; ++j)
			cout << s[i][j] << "&";

		cout << "\\text{R}_{" << s[i][N + 1] << "}\\\\\n";
	}
	cout << "\\hline\n&";

	for (int i = 1; i < N + 1; ++i)
		cout << "\\text{IR}_{" << s[N + 1][i] << "}&";
	cout << "\\\\\n\\hline\n&";

	const int DIF = 2 * (s[1][N] - s[1][1]);
	for (int i = 1; i < N + 1; ++i)
		cout << "\\text{RI}_{" << (N + s[0][i] + DIF) % N << "}&";

	cout << "\n\\end{array}\\]\n";

	return 0;
}
