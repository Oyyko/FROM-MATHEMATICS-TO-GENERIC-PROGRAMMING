// Something about Fast Power Algorithm a.k.a Exponentiation by squaring
// Note that this algorithm can be used for anything like a monoid
#include <iostream>
#include <vector>

using namespace std;

template <typename M, M e, M(mul)(M, M)>
M fast_power(M x, int k) // x^k
{
    M ans{e};
    do
    {
        if (k & 1)
        {
            ans = mul(ans, x);
        }
        k >>= 1;
        x = mul(x, x);
    } while (k);
    return ans;
}

template <typename M, M e, M(mul)(M, M)>
M fast_power_fib(M x, int k)
{
    M ans{e};
    int firstt{1};
    int secondd{1};
    int tmp;
    std::vector<M> fib_m;
    fib_m.emplace_back(x);
    fib_m.emplace_back(x);

    while (secondd <= k)
    {
        tmp = secondd;
        secondd = firstt + secondd;
        firstt = tmp;

        fib_m.emplace_back(*(fib_m.end() - 1) * *(fib_m.end() - 2));
    }
    while (firstt != secondd)
    {
        if (firstt <= k)
        {
            k -= firstt;
            ans *= *(fib_m.end() - 2);
        }
        tmp = firstt;
        firstt = secondd - firstt;
        secondd = tmp;

        fib_m.pop_back();
    }
    return ans;
}

int int_mul(int a, int b)
{
    return a * b;
}

int int_add(int a, int b)
{
    return a + b;
}

int main()
{
    printf("%d\n", fast_power<int, 1, int_mul>(2, 10));
    printf("%d\n", fast_power<int, 0, int_add>(6, 9));
    printf("%d\n", fast_power_fib<int, 1, int_mul>(3,3));
}