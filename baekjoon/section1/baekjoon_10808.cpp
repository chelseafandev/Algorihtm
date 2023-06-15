#include <iostream>
#include <vector>

int main()
{
    std::string input;
    std::cin >> input;

    // 26개의 알파벳의 카운트 값을 저장하는 벡터 선언
    //  - counts[0]은 input 문자열에 포함된 알파벳 `a`의 개수
    //  - counts[1]은 input 문자열에 포함된 알파벳 `b`의 개수
    //  ...
    //  - counts[25]은 input 문자열에 포함된 알파벳 `z`의 개수
    std::vector<int> counts(26, 0);

    // 배열의 인덱스 접근 활용
    for (const auto& alphabet : input)
    {
        counts[alphabet - 'a']++;
    }

    // 결과 출력
    for (const auto& count : counts)
    {
        std::cout << count << " ";
    }

    return 0;
}