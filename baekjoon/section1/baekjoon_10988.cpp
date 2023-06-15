#include <iostream>

int is_palindrome(const std::string& input)
{
    std::size_t input_len = input.length();

    for (int i = 0; i < (input_len/2); ++i)
    {
        if (input[i] != input[input_len - i - 1])
        {
            return 0;
        }
    }

    return 1;
}

int main()
{
    std::string input;
    std::cin >> input;
    std::cout << is_palindrome(input) << std::endl;
    return 0;
}