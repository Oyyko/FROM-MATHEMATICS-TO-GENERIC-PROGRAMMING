#include <iostream>

using namespace std;

// use the idea which is similar to "Fast Power" a.k.a "Exp by square"
template <typename SEGMENT>
SEGMENT fast_remainder(SEGMENT a, SEGMENT b)
{
    if (a <= b)
        return a;
    if (a <= b + b)
        return a - b;
    a = fast_remainder(a, b + b);
    if (a <= b)
        return a;
    return a - b;
}

template <typename SEGMENT>
SEGMENT gcd(SEGMENT a, SEGMENT b)
{
    while (a != b)
    {
        a = fast_remainder(a, b);
        std::swap(a, b);
    }
    return a;
}

template <typename SEGMENT>
SEGMENT remainder(SEGMENT a, SEGMENT b)
{
    if (a < b)
        return a;
    SEGMENT c{b};
    while (a >= c + c)
    {
        c = c + c;
    }
    a = a - c;
    while (c != b)
    {
        c = c / 2;
        if (c <= a)
            a = a - c;
    }
    return a;
}

// Give the ramainder and quotient at the same time
template <typename SEGMENT>
std::pair<int, SEGMENT> divide(SEGMENT a, SEGMENT b) //a / b
{
    if (a < b)
        return {0, a};
    SEGMENT d{b};
    while (a >= d + d)
    {
        d = d + d;
    }
    int c{1};
    a = a - d;
    while (d != b)
    {
        //d = d / 2;

        //Note that here we use the half function,because we haven't invent divide function
        // It seems that we cannot just write "d=d/2", so this algo can only be used at platform that
        // provides a native HALF operation.
        // Luckily a modern computer can do the operation ">>"
        // btw, d is always even in this scope

        d = d >> 1;

        c = c + c;
        if (d <= a)
        {
            a = a - d;
            c++;
        }
    }
    return {c, a};
}

// In order to do dividing on those platforms without native ">>" or "HALF" operation
// We use fibonacci to do the divide

template <typename SEGMANT>
std::pair<int, SEGMANT> divide_fib(SEGMANT a, SEGMANT b)
{
    if (a < b)
        return {0, a};
    SEGMANT c = b;
    SEGMANT tmp;
    int q{1};  // b ~ q
    int q1{1}; // c ~ q1
    int ans{};
    int tmp_q_trans;
    while (a >= c)
    {
        tmp = c;
        c = b + c;
        b = tmp;

        tmp_q_trans = q1;
        q1 = q + q1;
        q = tmp_q_trans;
    }
    while (b != c)
    {
        if (a >= b)
        {
            a -= b;
            ans += q;
        }
        tmp = b;
        b = c - b;
        c = tmp;

        tmp_q_trans = q;
        q = q1 - q;
        q1 = tmp_q_trans;
    }
    return {ans, a};
}

int main()
{
    printf("%d\n",2222);
    cout << divide(100, 3).first << divide(100, 3).second << endl;
    cout << divide_fib(100, 3).first << divide_fib(100, 3).second << endl;
}