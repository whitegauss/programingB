#include <cmath>
#include <cstdlib>
#include <iostream>
#include <random>

using namespace std;

int main() {
	const size_t totalSamples = 10000000;   // 総試行回数

	random_device rd;
	mt19937 rng(rd());
	uniform_real_distribution<double> dist(-1.0, 1.0);

	size_t inside = 0;
	const double piTrue = acos(-1.0);

	size_t nextReport = 10;  // 次に出力する試行回数 (10, 100, 1000, ..., 10^7)

	for (size_t i = 1; i <= totalSamples; ++i) {
		const double x = dist(rng);
		const double y = dist(rng);
		if (x * x + y * y <= 1.0) {
			++inside;
		}

		if (i == nextReport) {
			const double piEstimate = 4.0 * static_cast<double>(inside) / static_cast<double>(i);
			const double error = fabs(piEstimate - piTrue);
			cout << i << ' ' << error << "\n";

			nextReport *= 10;  // 10倍ずつ増やす
		}
	}

	return EXIT_SUCCESS;
}