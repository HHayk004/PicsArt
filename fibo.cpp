#include <iostream>

long long fibonacci(int);

int main()
{
    int num = 0;

    do {
        std::cout << "Enter the num: ";
        std::cin >> num;
    } while (num < 0);

    std::cout << fibonacci(num) << std::endl;

    return 0;
}

long long fibonacci(int n)
{
    if (n <= 1)
    {
        return n;
    }

    long long prev = 0, next = 1;
    for (int i = 1; i < n; ++i)
    {
        long tmp = prev;
        prev = next;
        next += tmp;
    }

    return next;
}
