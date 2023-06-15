#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    // `ctrl + D` in linux
    int n = 0;
    while(std::cin >> n)
    {
        long long positional_number = 1;
        long long target = 1;
        while(true)
        {
            if (target % n == 0)
            {
                break;
            }

            positional_number++;
            target = (target * 10) + 1;
            target %= n; // 모듈러연산!!
        }

        std::cout << positional_number << '\n';
    }

    return 0;
}