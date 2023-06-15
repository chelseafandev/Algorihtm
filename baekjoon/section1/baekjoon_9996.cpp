#include <iostream>
#include <vector>

// itr1 : 비교할 첫번째 문자열의 iterator
// itr2 : 비교할 두번째 문자열의 iterator
// len : 비교할 문자열의 길이
template <typename IteratorT1, typename IteratorT2>
bool check_matching(IteratorT1 itr1, IteratorT2 itr2, int len)
{
    for (int i = 0; i < len; ++i)
    {
        if (*itr1 != *itr2)
        {
            return false;
        }

        itr1++;
        itr2++;
    }

    return true;
}

int main()
{
    int file_count = 0; // 파일의 개수
    std::cin >> file_count;

    std::string pattern; // 패턴: 알파벳 소문자 여러 개와 별표(*) 하나로 이루어진 문자열(단, 별표는 문자열의 시작과 끝에 있지 않음)
    std::cin >> pattern;

    std::string filename;
    std::vector<std::string> filenames;
    for (int i = 0; i < file_count; ++i)
    {
        std::cin >> filename;
        filenames.push_back(filename);
    }

    bool is_matched = false;
    
    for (int i = 0; i < file_count; ++i)
    {   
        // 주의!! 별표(*)를 제외한 패턴의 길이보다 파일명 길이가 작은 경우 예외 처리
        if (pattern.length() - 1 > filenames[i].length())
        {
            std::cout << "NE" << std::endl;
            continue;
        }

        std::size_t pos = pattern.find('*');
        is_matched = check_matching(pattern.substr(0, pos).begin(), filenames[i].begin(), pos);
        if (is_matched == true)
        {
            is_matched = check_matching(pattern.substr(pos + 1, pattern.length() - pos - 1).rbegin(), filenames[i].rbegin(), pattern.length() - pos - 1);
        }

        if (is_matched == true)
        {
            std::cout << "DA" << std::endl;
        }
        else
        {
            std::cout << "NE" << std::endl;
        }
    }

    return 0;
}