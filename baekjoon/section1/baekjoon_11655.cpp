#include <iostream>

int main()
{
    std::string input;
    std::getline(std::cin, input);

    std::string result = "";
    for(const auto& character : input)
    {
        // 알파벳을 13글자 밀어준다
        // A(65) ~ Z(90)
        // a(97) ~ z(122)
        if (character < 'A' || character > 'z')
        {
            result += character;
            continue;
        }

        // 대소문자 구분은 어떻게? 'Z'가 기준
        if (character <= 'Z')
        {
            // 대문자
            unsigned char tmp = character + 13;
            if (tmp > 'Z')
            {
                result += 'A' + (tmp - 'Z' - 1);
            }
            else
            {
                result += tmp;
            }
        }
        else
        {
            // 소문자
            // character에 13을 더한 결과가, 127을 초과하는 경우가 발생할 수 있으므로 tmp 변수를 char가 아닌 unsinged char 타입으로 선언하자
            unsigned char tmp = character + 13;
            if (tmp > 'z')
            {

                result += 'a' + (tmp - 'z' - 1);
            }
            else
            {
                result += tmp;
            }
        }
    }

    std::cout << result << std::endl;

    return 0;
}