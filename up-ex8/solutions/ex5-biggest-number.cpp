#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

static bool my_comparison_func(const int& lhs, const int& rhs) {
    std::string lhs_string = std::to_string(lhs);
    std::string rhs_string = std::to_string(rhs);
    if (lhs_string + rhs_string > rhs_string + lhs_string) {
        return true;
    }
}

std::string largestNumber(std::vector<int> nums) {
    std::sort(nums.begin(), nums.end(), my_comparison_func);
    std::ostringstream result;
    std::copy(nums.begin(), nums.end(), std::ostream_iterator<std::string>(result, ""));
    return result.str();
}

int main() {
    
    return 0;
}