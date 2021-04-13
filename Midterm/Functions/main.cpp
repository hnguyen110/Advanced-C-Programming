#include <iostream>
#include <string>

using namespace std;

template<typename T>
void add(const T firstArr[], const T secondArr[], T thirdArr[], size_t length) {
    for (size_t i = 0; i < length; ++i) {
        thirdArr[i] = firstArr[i] + secondArr[i];
    }
}

template<>
void
add<std::string>(const std::string firstArr[], const std::string secondArr[], std::string thirdArr[], size_t length) {
    for (size_t i = 0; i < length; ++i) {
        thirdArr[i] = firstArr[i] + ' ' + secondArr[i];
    }
}

int main() {
    std::string s[]{"yes", "no", "who", "when", "why"},
            t[]{"yes", "no", "who", "when", "why"},
            u[5]{};
    int a[]{1, 2, 3, 4, 5},
            b[]{5, 4, 3, 2, 1},
            c[5];
    double d[]{1.1, 2.2, 3.3, 4.4, 2.2},
            e[]{1.1, 2.2, 3.3, 4.4, 2.2},
            f[5];

    add(s, t, u, 5);
    for (auto &e : u)
        std::cout << e << '|';
    std::cout << std::endl;

    add(a, b, c, sizeof a / sizeof(int));
    for (auto &e : c)
        std::cout << e << ' ';
    std::cout << std::endl;

    add(d, e, f, sizeof d / sizeof(double));
    for (auto &e : f)
        std::cout << e << ' ';
    std::cout << std::endl;
}  