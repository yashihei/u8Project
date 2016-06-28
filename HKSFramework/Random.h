#pragma once
#include <random>

class Random {
public:
	Random() {
		std::random_device rd;
		setSeed(rd());
	}
	void setSeed(int seed) {
		mt.seed(seed);
	}
	int next(int n) {
		return next(0, n);
	}
	double nextDouble() {
		return next(0.0, 1.0);
	}
	int nextPlusMinus(int n) {
		return next(-n, n);
	}
	double nextPlusMinus(double n) {
		return next(-n, n);
	}
	int next(int a, int b) {
		std::uniform_int_distribution<int> dice(a, b);
		return dice(mt);
	}
	double next(double a, double b) {
		std::uniform_real_distribution<double> score(a, b);
		return score(mt);
	}
private:
	std::mt19937 mt;
};
