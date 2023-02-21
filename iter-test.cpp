#include <chrono>
#include <iostream>
#include <vector>
#include <array>

constexpr int ARBITARY_BIG = 10'000'000;
constexpr int ARBITARY_SMALL = 1;


// 생성자에 현재 시간이 측정되고 소멸자에 걸린 시간이 출력된다.
class timer {
    using time_point = std::chrono::time_point<std::chrono::steady_clock, std::chrono::duration<long long, std::ratio<1, 1000000000>>>;
    public:
        timer(const std::string& name) : name_(name), start_(now()) {}
        ~timer() {
            print_result(name_, start_, now());
        }
    private:
        std::string name_;
        timer::time_point start_;

        void print_result(const std::string& name, timer::time_point start, timer::time_point end) const noexcept {
            std::chrono::duration<double> sec = end - start;
            std::cout << /*name << " : " << */ sec.count() << std::endl;
        }

        inline static std::chrono::steady_clock::time_point now() noexcept {
            return std::chrono::high_resolution_clock::now();
        }
};

// 1번 방법.
void range_based() { 
    std::vector<int> vec(ARBITARY_BIG, 0);

    timer t("1. range_based");

    for (auto &rg : vec)
    {
        rg = ARBITARY_SMALL;
    }
}
// 1-1번 방법. 1번 방법을 일반 for loop로 풀어 쓴 것이다.
// 이 코드를 보면 알겠지만, iterator를 직접 쓰는 것과 range-based for loop는 속도 차이가 날 수 없다.
// 그런데도 속도 차이가 나는 이유는 아래에서 설명하겠다.
void range_based_expanded() {
    std::vector<int> vec(ARBITARY_BIG, 0);

    timer t("1-1. expanded_range_based");

    {
        auto &&range = vec;
        auto begin = range.begin();
        auto end = range.end();
        for (; begin != end; ++begin)
        {
            auto &rg = *begin;
            rg = ARBITARY_SMALL;
        }
    }
}

// 2번 방법. vector의 subscript operator로 접근하였다.
void index_for() {
    std::vector<int> vec(ARBITARY_BIG, 0);

    timer t("2. index_for");

    for (int i = 0; i < ARBITARY_BIG; i++)
    {
        vec[i] = ARBITARY_SMALL;
    }
}

// 3번 방법. vector에 접근하지 않고 vector::data에 직접 접근하였다.
void index_vec_data() {
    std::vector<int> vec(ARBITARY_BIG, 0);
    auto p_data = vec.data();

    timer t("3. index_for_vec_data");

    for (int i = 0; i < ARBITARY_BIG; i++)
    {
        p_data[i] = ARBITARY_SMALL;
    }
}

// 3-1번 방법. std::vector 대신에 c-style array를 쓰면 어떨까?
void index_c_array() {
    int* arr = new int[ARBITARY_BIG]{};

    timer t("3-1. index_for_c_array");

    for (int i = 0; i < ARBITARY_BIG; i++)
    {
        arr[i] = ARBITARY_SMALL;
    }
    delete[] arr;
}

// 3-2 c-style array를 0으로 초기화하지 않고 사용하면 어떨까?
void index_c_array_no_zero_init() {
    int* arr = new int[ARBITARY_BIG];

    timer t("3-2. range_based_no_zero_init");

    for (int i = 0; i < ARBITARY_BIG; i++)
    {
        arr[i] = ARBITARY_SMALL;
    }

    delete[] arr;
}


// 4번 방법. iterator를 사용한 방법. 이 방법은 원문에 제공된 방법과 동일하게 순회하였다. 
// iter++으로 되어있음에 주목하라.
void iterator_for() {
    std::vector<int> vec(ARBITARY_BIG, 0);

    timer t("4. iterator_for");

    for (auto iter = vec.begin(), end = vec.end(); iter != end; iter++)
    {
        *iter = ARBITARY_SMALL;
    }
}

// 4-1번 방법. 이번에는 ++iter를 사용하였다.
void iterator_post_increment() {
    std::vector<int> vec(ARBITARY_BIG, 0);

    timer t("4-1. iterator_post_increment");

    for (auto iter = vec.begin(), end = vec.end(); iter != end; ++iter)
    {
        *iter = ARBITARY_SMALL;
    }
}

int main()
{
    // 1.
    range_based();
    // 1-1.
    range_based_expanded();

    // 2.
    index_for();
    // 3.
    index_vec_data();
    // 3-1.
    index_c_array();
    // 3-2.
    index_c_array_no_zero_init();

    // 4.
    iterator_for();
    // 4-1.
    iterator_post_increment();
}
