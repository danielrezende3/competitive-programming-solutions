#include <gmpxx.h>
#include <iostream>

int main() {
    mpz_class result;
    mpz_ui_pow_ui(result.get_mpz_t(), 3, 10000000);  // Calculate 3^10^7
    std::cout << result << std::endl;
    return 0;
}
