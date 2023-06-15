#include <iostream>
#include <vector>
#include <algorithm>

#define ODD_COUNT_CASE_NONE 0            // 홀수 개수인 알파벳이 없는 경우
#define ODD_COUNT_CASE_ONLY_ONE 1        // 홀수 개수인 알파벳이 존재하고, 그 개수가 1개인 경우
#define ODD_COUNT_CASE_MORE_THAN_THREE 2 // 홀수 개수인 알파벳이 존재하고, 그 개수가 3개 이상인 경우

std::string make_palindrome(const std::vector<int>& alphabet_count)
{
    char odd_count_alphabet; // 홀수 개수인 알파벳
    bool is_exist_odd_count = false;
    for (int i = 0; i < alphabet_count.size(); ++i)
    {
        // 홀수 개수인 알파벳이 존재
        if ((alphabet_count[i] != 0) && (alphabet_count[i] % 2 == 1))
        {
            // 그런데 이전에 홀수 개수인 알파벳이 존재했다면
            if (is_exist_odd_count == true)
            {
                // 해당 input은 팰린드롬이 아님
                return std::string("I'm Sorry Hansoo");
            }

            is_exist_odd_count = true;
            odd_count_alphabet = i + 'A';
        }
    }

    // 팰린드롬 문자열의 절반만 만들어 놓고 나머지 부분은 std::reverse() 함수를 활용하여 완성
    
    // 팰린드롬 문자열의 절반 만들기
    std::string partial_result; 
    int odd_count_case = ODD_COUNT_CASE_NONE;
    for (int i = 0; i < alphabet_count.size(); ++i)
    {
        if (alphabet_count[i] % 2 == 0)
        {
            if (alphabet_count[i] != 0) // 알파벳의 개수가 (0이 아닌)짝수인 경우
            {
                char tmp = i + 'A';
                for (int j = 0; j < alphabet_count[i]/2; ++j)
                {
                    partial_result += tmp;
                }
            }
        }
        else if (alphabet_count[i] % 2 == 1)
        {
            if (alphabet_count[i] != 1) 
            {
                // 홀수 개수인 알파벳이 존재하고, 그 개수가 3개 이상인 경우
                char tmp = i + 'A';
                for (int j = 0; j < alphabet_count[i]/2; ++j)
                {
                    partial_result += tmp;
                }
                odd_count_case = ODD_COUNT_CASE_MORE_THAN_THREE;
            }
            else
            {
                // 홀수 개수인 알파벳이 존재하고, 그 개수가 1개인 경우
                // 팰린드롬의 중앙에 위치해야함
                odd_count_case = ODD_COUNT_CASE_ONLY_ONE;
            }
        }
    }

    // std::reverse() 함수를 활용하여 팰린드롬 문자열 완성하기
    std::string result;
    if (odd_count_case == ODD_COUNT_CASE_NONE)
    {
        result += partial_result;
        std::reverse(partial_result.begin(), partial_result.end());
        result += partial_result;
    }
    else
    {
        result += partial_result;
        result += odd_count_alphabet;
        std::reverse(partial_result.begin(), partial_result.end());
        result += partial_result;
    }

    return result;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::string input;
    std::cin >> input;

    std::vector<int> alphabet_count(26, 0);
    for (int i = 0; i < input.length(); ++i)
    {
        alphabet_count[input[i] - 'A']++;
    }

    std::cout << make_palindrome(alphabet_count) << std::endl;

    return 0;
}