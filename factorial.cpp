#include <iostream>

long long foo(int);

int main()
{
    int num = 0;

    do {
        std::cout << "Enter the num: ";
        std::cin >> num;
    } while (num < 0);

    std::cout << foo(num) << std::endl;

    return 0;
}

long long foo(int n)
{
    long long answer = 1;
    for (int i = 1; i <= n; ++i)
    {
        answer *= i;
    }

    return answer;
}
