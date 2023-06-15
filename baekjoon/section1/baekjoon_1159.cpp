#include <iostream>
#include <vector>

int main()
{
    int player_num = 0;
    std::cin >> player_num;

    std::vector<std::string> player_list;
    for (int i = 0; i < player_num; ++i)
    {
        std::string player;
        std::cin >> player;
        player_list.push_back(player);
    }

    std::vector<int> alphabet_count(26, 0);
    for (const auto& player : player_list)
    {
        alphabet_count[player[0] - 'a']++;
    }

    bool is_exist = false;
    for (int i = 0; i < alphabet_count.size(); ++i)
    {
        if (alphabet_count[i] >= 5)
        {
            is_exist = true;
            char tmp = i + 'a';
            std::cout << tmp;
        }
    }

    if (is_exist == true)
    {
        std::cout << std::endl;
    }
    else
    {
        std::cout << "PREDAJA" << std::endl;
    }

    return 0;
}