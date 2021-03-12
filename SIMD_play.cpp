#include <iostream>
#include <immintrin.h>
#include "../cryless/cry.h"

int main()
{
    //__m256 evens = _mm256_set_ps(1, 2, 3, 4, 5, 6, 7, 8);
    //__m256 odds = _mm256_set_ps(1, 2, 3, 4, 5, 6, 7, 8);
    auto evens = _mm256_set_ps(1, 2, 3, 4, 5, 6, 7, 8);
    auto odds = _mm256_set_ps(1, 2, 3, 4, 5, 6, 7, 8);
    auto result = _mm256_add_ps(evens, odds);

    float *f = (float *)&result;
    std::copy(f, f + 8, std::ostream_iterator<float>(std::cout, " "));
    std::cout << std::endl;
    return 0;
}
