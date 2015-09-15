#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

const int N = 100000;

bool is_prime[N+1];
vector<int> primes, cool_numbers;

int get_reverse(int k) {
    int k2 = 0;
    while (k) {
        k2 = k2*10 + k%10;
        k /= 10;
    }
    return k2;
}

void ciur() {
    for (int i=2; i<=N; i++)
        if (!is_prime[i]) {
            primes.push_back(i);
            for (int j=i+i; j<=N; j+=i)
                is_prime[j] = true;
        }
}

void get_cool_numbers() {
    for (auto prime : primes) {
        int reversed = get_reverse(prime);
        if (!is_prime[reversed] && prime != reversed) {
            cool_numbers.push_back(prime);
        }
    }
}

int main() {
    ciur();
    get_cool_numbers();

    int x; cin >> x; x -= 1;
    if (x > cool_numbers.size() - 1) {
        cout << "-1\n";
    } else {
        cout << cool_numbers[x] << "\n";
    }

    return 0;
}
