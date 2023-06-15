#include <iostream>

unsigned long recursive_call(const unsigned long& A, const unsigned long& B, const unsigned long& C)
{
    if (B == 1)
    {
        return A % C;
    }

    unsigned long result = recursive_call(A, B/2, C);
    result = (result * result) % C;

    // B가 홀수인 경우 처리
    if (B % 2 == 1)
    {
        result = (result * A) % C;
    }

    return result;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    unsigned long A, B, C = 0;

    std::cin >> A;
    std::cin >> B;
    std::cin >> C;

    auto result = recursive_call(A, B, C);
    std::cout << result << std::endl;

    return 0;
}