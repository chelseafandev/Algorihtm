#include <iostream>
#include <vector>
#include <map>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int test_case_count = 0;
    std::cin >> test_case_count;

    std::vector<int> results;
    for (int i = 0; i < test_case_count; ++i)
    {
        int dress_kind_count = 0;
        std::cin >> dress_kind_count;

        std::string name;
        std::string dress_kind;
        std::map<std::string, int> count_per_dress_kind;
        for (int i = 0; i < dress_kind_count; ++i)
        {
            std::cin >> name;
            std::cin >> dress_kind;
            auto found = count_per_dress_kind.find(dress_kind);
            if (found != count_per_dress_kind.end())
            {
                count_per_dress_kind[dress_kind]++;
            }
            else
            {
                count_per_dress_kind[dress_kind] = 1;
            }
        }
        
        // 해당 의상 종류를 입지 않는 경우를 포함시켜서 전체 경우의 수를 구하고나서
        // 어떠한 의상 종류도 입지 않는 경우(오직 1가지 케이스)를 빼준다
        long long result = 1;
        for (const auto &dress_kind : count_per_dress_kind)
        {
            result *= (dress_kind.second + 1);
        }
        result = result - 1;

        results.push_back(result);
    }

    for (const auto& result : results)
    {
        std::cout << result << '\n';
    }

    return 0;
}