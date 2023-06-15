#include <iostream>
#include <vector>
#include <stack>

bool is_goold_word(const std::string& word)
{
    std::stack<char> container;

    container.push(word[0]);
    for (int i = 1; i < word.length(); ++i)
    {
        if (container.empty() == true)
        {
            container.push(word[i]);
            continue;
        }

        if (container.top() == word[i])
        {
            container.pop();
        }
        else
        {
            container.push(word[i]);
        }
    }

    if (container.empty() == true)
    {
        return true;
    }

    return false;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int count = 0;
    std::cin >> count;

    std::vector<std::string> words;
    std::string tmp;
    for (int i = 0; i < count; ++i)
    {
        std::cin >> tmp;
        words.emplace_back(tmp);
    }
    
    int result = 0;
    for (const auto& word : words)
    {
        if (is_goold_word(word) == true)
        {
            result++;
        }
    }

    std::cout << result << '\n';

    return 0;
}