#include <iostream>
#include <vector>

namespace pns
{
class permutation
{
    // TODO: int이외의 타입들도 처리가 가능하게끔 클래스 템플릿으로 만들어보기
    using type_of_n = std::vector<int>;
    using type_of_result = std::vector<std::vector<int>>;

public:
    // Parameters:
    //      n: 순열을 구하기 위한 n개의 원소를 갖는 집합
    //      size_of_n: 집합 n의 원소 개수
    //      r: 집합 n중 순열을 구하기 위해 택하는 원소의 개수
    permutation(const type_of_n& n, unsigned int size_of_n, unsigned int r);
    ~permutation();

    // Returns:
    //      type_of_result: 순열의 결과
    type_of_result make_permutation();

private:
    // Parameters:
    //      depth: swap을 수행할 대상이되는 인덱스 값
    //      result: 재귀 호출의 base condition에서 얻어진 결과를 해당 변수에 추가하기때문에 변경될 수 있음(reference인 이유)
    // Returns:
    //      type_of_result: 순열의 결과
    void recursive_call_for_permutation(unsigned int depth, type_of_result& result);

    type_of_n n_;
    unsigned int size_of_n_;
    unsigned int r_;
};
}