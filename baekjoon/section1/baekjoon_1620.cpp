#include <iostream>
#include <vector>
#include <map>

int main()
{
    // 백준에서 문제풀때는 기본적으로 선언하고 시작하자!
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    //////////////////////////////////////
    
    int pocketmon_count = 0;
    std::cin >> pocketmon_count;

    int problem_count = 0;
    std::cin >> problem_count;

    std::map<std::string, std::string> pocketmaon_dogam;

    std::string pocketmon_name;
    for (int i = 1; i <= pocketmon_count; ++i)
    {
        std::cin >> pocketmon_name;
        pocketmaon_dogam.insert(std::pair<std::string, std::string>(pocketmon_name, std::to_string(i)));
        pocketmaon_dogam.insert(std::pair<std::string, std::string>(std::to_string(i), pocketmon_name));
    }

    std::string input;
    std::vector<std::string> problems;
    for (int i = 0; i < problem_count; ++i)
    {
        std::cin >> input;
        problems.push_back(input);
    }

    for (const auto& problem : problems)
    {
        // 개행은 std::endl 보다 '\n'을 사용하자!
        std::cout << pocketmaon_dogam[problem] << '\n';
    }

    return 0;
}