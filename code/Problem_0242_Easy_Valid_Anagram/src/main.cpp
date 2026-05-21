#include "solutions.h"

#include <cstdlib>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

namespace {

[[maybe_unused]] void print_value(bool value) {
    std::cout << std::boolalpha << value;
}

[[maybe_unused]] void print_value(char value) {
    std::cout << value;
}

[[maybe_unused]] void print_value(int value) {
    std::cout << value;
}

[[maybe_unused]] void print_value(const std::string& value) {
    std::cout << '"' << value << '"';
}

template <typename T>
void print_value(const std::vector<T>& values) {
    std::cout << '[';
    for (std::size_t i = 0; i < values.size(); ++i) {
        if (i > 0) {
            std::cout << ", ";
        }
        print_value(values[i]);
    }
    std::cout << ']';
}

template <typename Fn>
int run_selected_solution(int argc, char* argv[], Fn&& fn) {
    const std::string_view selected_id = argc > 1 ? std::string_view(argv[1]) : std::string_view{};
    bool ran_solution = false;

    solutions::for_each_solution([&](const solutions::SolutionInfo& solution_info,
                                     auto solution_type) {
        if (!selected_id.empty() && selected_id != solution_info.id) {
            return;
        }

        ran_solution = true;
        std::cout << "\n== " << solution_info.id << " ==\n";
        std::cout << solution_info.method << '\n';
        fn(solution_type);
    });

    if (!ran_solution) {
        std::cerr << "No solution id matched '" << selected_id << "'.\n";
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

}  // namespace

int main(int argc, char* argv[]) {
    return run_selected_solution(argc, argv, [](auto solution_type) {
        using Solution = typename decltype(solution_type)::type;
        Solution solution;

        const std::string s {"anagram"};
        const std::string t {"nagaram"};
        const auto result = solution.is_anagram(s, t);
        std::cout << "s = ";
        print_value(s);
        std::cout << ", t = ";
        print_value(t);
        std::cout << "\nis anagram = ";
        print_value(result);
        std::cout << "\n";
    });
}
