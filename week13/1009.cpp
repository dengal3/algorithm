#include <iostream>
#include <string.h>
#include <stdio.h>
#include <cmath>
#include <vector>
using namespace std;

bool composite[64];
void fast_gen_prime(int maxn) {
		for (int i = 2; i < maxn; i++) {
				if (composite[i]) continue;
				for (int j = i*i; j <= maxn; j += i) {
						composite[j] = true;
				}
		}
}

bool isPrime(long long n) {
		for (long long i = 2; i*i <= n; i++) {
				if (n % i == 0)
					return false;
		}
		return true;
}

vector<long long> factor(long long n) {
		vector<long long> ret;
		for (long long i = 2; i*i <= n; i++) {
				while (n % i == 0) {
						ret.push_back(i);
						n /= i;
				}
		}
		if (n > 1) ret.push_back(n);
		return ret;
}

int main() {
		int k;
		cin >> k;
		memset(composite, false, 64);
		fast_gen_prime(k);
		for (int i = 2; i <= k; i++) {
				if (!composite[i]) {
					if (i == 61) continue;
					long long n = 1;
					for (int j = 0; j < i; j++)
						n *= 2;
					n--;
					if (!isPrime(n)) {
							vector<long long> factors = factor(n);
							printf("%lld", factors[0]);
							for (int j = 1; j < factors.size(); j++) {
									printf(" * %lld", factors[j]);
							}
							printf(" = %lld = ( 2 ^ %d ) - 1\n", n, i);
					}
				}
		}
}