#include <iostream>

int N;
auto prefix = "____";

void print(int n, const std::string &s) {
    for (int i = 0; i < N - n; ++i) {
        std::cout << prefix;
    }
    std::cout << s << '\n';
}

void recursive(int n) {
    print(n, "\"재귀함수가 뭔가요?\"");
    if (n == 0) {
        print(n, "\"재귀함수는 자기 자신을 호출하는 함수라네\"");
    } else {
        print(n, "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.");
        print(n, "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.");
        print(n, "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"");
        recursive(n - 1);
    }
    print(n, "라고 답변하였지.");
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    std::cin >> N;

    std::cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n";

    recursive(N);
}

