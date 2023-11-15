#include <iostream>


long long factorial_iterative(int);


int main()
{
    int num = 0;

    do {
        std::cout << "Enter the num: ";
        std::cin >> num;
    } while (num < 0);


    std::cout << factorial_iterative(num) << std::endl;

    return 0;
}


long long factorial_iterative(int n)

{
    long long answer = 1;
    for (int i = 1; i <= n; ++i)
    {
        answer *= i;
    }

    return answer;
}
