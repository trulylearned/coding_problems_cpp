#include "solutions.h"

#include <cstdlib>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

namespace {

template <typename T>
void print_vector(const std::vector<T>& values) {
    std::cout << '[';
    for (std::size_t i = 0; i < values.size(); ++i) {
        if (i > 0) {
            std::cout << ", ";
        }
        std::cout << values[i];
    }
    std::cout << ']';
}

template <typename T>
void print_nested_vector(const std::vector<std::vector<T>>& values) {
    std::cout << '[';
    for (std::size_t i = 0; i < values.size(); ++i) {
        if (i > 0) {
            std::cout << ", ";
        }
        print_vector(values[i]);
    }
    std::cout << ']';
}

[[maybe_unused]] void print_string_groups(const std::vector<std::vector<std::string>>& groups) {
    std::cout << '[';
    for (std::size_t i = 0; i < groups.size(); ++i) {
        if (i > 0) {
            std::cout << ", ";
        }
        std::cout << '[';
        for (std::size_t j = 0; j < groups[i].size(); ++j) {
            if (j > 0) {
                std::cout << ", ";
            }
            std::cout << '"' << groups[i][j] << '"';
        }
        std::cout << ']';
    }
    std::cout << ']';
}

template <typename Fn>
int run_selected_solution(int argc, char* argv[], Fn&& fn) {
    const std::string_view selected_id = argc > 1 ? std::string_view(argv[1]) : std::string_view{};
    bool ran_solution = false;

    std::cout << std::boolalpha;

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
        using {{SOLUTION_CLASS_NAME}} = typename decltype(solution_type)::type;
        {{SOLUTION_CLASS_NAME}} solution;

        {{DEBUG_INPUT_SETUP}}
        {{DEBUG_CALL_AND_PRINT}}
    });
}
