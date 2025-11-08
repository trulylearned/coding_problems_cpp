#pragma once
#include <vector>
#include <unordered_map>
#include <numeric>     // For std::iota
#include <algorithm>   // For std::max, std::swap

class Solution {
private:
    // A DSU (Union-Find) data structure with path compression
    // and union-by-size. All names are snake_case as required.
    struct DisjointSetUnion {
        std::vector<int> parent_;
        std::vector<int> component_size_;
        int max_component_size_ = 0;

        DisjointSetUnion(int n) : parent_(n), component_size_(n, 1) {
            // Initially, every node is its own parent
            std::iota(parent_.begin(), parent_.end(), 0);
            if (n > 0) {
                max_component_size_ = 1;
            }
        }

        // Find the representative (root) of the set for 'x'
        int find_set(int x) {
            if (parent_[x] == x) {
                return x;
            }
            // Path compression
            return parent_[x] = find_set(parent_[x]);
        }

        // Merge the two sets containing 'a' and 'b'
        void unite_sets(int a, int b) {
            int root_a = find_set(a);
            int root_b = find_set(b);
            
            if (root_a != root_b) {
                // Union-by-size: attach smaller tree to larger
                if (component_size_[root_a] < component_size_[root_b]) {
                    std::swap(root_a, root_b);
                }
                parent_[root_b] = root_a;
                component_size_[root_a] += component_size_[root_b];
                
                // Track the largest component size as we go
                max_component_size_ = std::max(max_component_size_, component_size_[root_a]);
            }
        }
        
        int get_max_component_size() const {
            return max_component_size_;
        }
    };

public:
    /////////////////////////////////////////////////////////////////
    // Method:      Disjoint Set Union (Union-Find)
    // Time Cmplx:  O(N * alpha(N)) -> practically O(N)
    // Space Cmplx: O(N)
    // Remarks:     More complex, but a powerful pattern for
    //              connectivity problems.
    /////////////////////////////////////////////////////////////////
    int longestConsecutive(std::vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        // Map sparse values (e.g., 1,000,000) to dense indices (e.g., 0)
        std::unordered_map<int, int> val_to_index;
        val_to_index.reserve(nums.size());

        int current_index = 0;
        for (int val : nums) {
            if (!val_to_index.contains(val)) {
                val_to_index[val] = current_index++;
            }
        }

        // Initialize DSU with one component for each unique number
        DisjointSetUnion dsu(current_index);

        // Iterate through the mapped values and unite neighbors
        for (auto const& [val, index] : val_to_index) {
            // Check if val+1 exists in the map
            auto it = val_to_index.find(val + 1);
            if (it != val_to_index.end()) {
                // If so, unite the components for 'val' and 'val+1'
                dsu.unite_sets(index, it->second);
            }
        }

        return dsu.get_max_component_size();
    }
};