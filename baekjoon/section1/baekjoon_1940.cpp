#include <iostream>
#include <vector>

inline void recursive_call(const std::vector<int>& material, const int& reference, int start, std::vector<int>& v, std::vector<std::vector<int>>& result)
{
    if (v.size() == 2)
    {
        int sum = 0;
        for (const auto& num : v)
        {
            sum += num;
        }

        if (sum == reference)
        {
            result.emplace_back(v);
        }

        return;
    }

    for (int i = start; i < material.size(); ++i)
    {
        v.emplace_back(material[i]);
        recursive_call(material, reference, i + 1, v, result);
        v.pop_back();
    }
}

inline std::vector<std::vector<int>> make_combination(const std::vector<int>& material, const int& reference)
{
    std::vector<std::vector<int>> result; // rvo!
    std::vector<int> v;
    recursive_call(material, reference, 0, v, result);
    return result;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int material_count = 0;
    std::cin >> material_count;

    int reference = 0;
    std::cin >> reference;

    std::vector<int> material;
    for (int i = 0; i < material_count; ++i)
    {
        int tmp = 0;
        std::cin >> tmp;
        material.emplace_back(tmp);
    }

    auto result = make_combination(material, reference);

    std::cout << result.size() << std::endl;

    return 0;
}