#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n, m, a, b;
    cin >> n >> m >> a >> b;

    if (b / m >= a) {
        cout << n * a;
    }

    else if ((n % m) * a >= b) {
        cout << (n / m) * b + (n % m != 0) * b;
    }

    else {
        cout << (n / m) * b + (n % m) * a;
    }

    return 0;
}
