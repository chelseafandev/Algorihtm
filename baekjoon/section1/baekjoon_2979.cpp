#include <iostream>
#include <vector>

void counting_truck(std::vector<int>& output, int start, int end)
{
    for (int i = start; i < end; ++i)
    {
        output[i]++;
    }
}

int main()
{
    int A = 0;
    int B = 0;
    int C = 0;

    std::cin >> A;
    std::cin >> B;
    std::cin >> C;

    int first_start_time = 0;
    int first_end_time = 0;
    int second_start_time = 0;
    int second_end_time = 0;
    int third_start_time = 0;
    int third_end_time = 0;

    std::cin >> first_start_time;
    std::cin >> first_end_time;
    std::cin >> second_start_time;
    std::cin >> second_end_time;
    std::cin >> third_start_time;
    std::cin >> third_end_time;

    // 해당 시간대에 몇대의 차가 주차되어있는지 카운팅하는 벡터 선언
    // 입력으로 주어지는 시간이 1과 100 사이이므로 100만큼 할당
    std::vector<int> truck_counts(100, 0);

    counting_truck(truck_counts, first_start_time, first_end_time);
    counting_truck(truck_counts, second_start_time, second_end_time);
    counting_truck(truck_counts, third_start_time, third_end_time);

    int result = 0;
    for (const auto& count : truck_counts)
    {
        if (count == 1)
        {
            result += (count*A);
        }
        else if (count == 2)
        {
            result += (count*B);
        }
        else if (count == 3)
        {
            result += (count*C);
        }
    }

    std::cout << result << std::endl;

    return 0;
}