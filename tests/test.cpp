// test.cpp

#include <bits/stdc++.h>
#include "../solutions/solution.cpp"  // Adjust the path if needed

using namespace std;

// Utility function to print vector of vector of ints
void printVectorPairs(const vector<vector<int>>& vec) {
    cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << "[" << vec[i][0] << "," << vec[i][1] << "]";
        if (i < vec.size() - 1) cout << ",";
    }
    cout << "]";
}

// Compare two vector of pairs
bool compareVectorPairs(const vector<vector<int>>& a, const vector<vector<int>>& b) {
    return a == b;
}

// Check if one is prefix of another
bool isPrefix(const vector<vector<int>>& full, const vector<vector<int>>& prefix) {
    if (prefix.size() > full.size()) return false;
    for (size_t i = 0; i < prefix.size(); ++i)
        if (full[i] != prefix[i]) return false;
    return true;
}

// Run individual test cases
void runTestCase(const vector<int>& input, const vector<vector<int>>& expected, int& passed, int& total, bool isPartial = false) {
    total++;
    Solution sol;
    vector<vector<int>> result = sol.minimumAbsDifference(const_cast<vector<int>&>(input));

    bool passedTest = isPartial ? isPrefix(result, expected) : compareVectorPairs(result, expected);

    if (passedTest) {
        passed++;
        cout << "✅ Test " << total << " passed.\n";
    } else {
        cout << "❌ Test " << total << " failed.\n";
        cout << "Input (first 10): ";
        for (int i = 0; i < min(10, (int)input.size()); ++i) cout << input[i] << " ";
        cout << "\nExpected: "; printVectorPairs(expected);
        cout << "\nGot     : "; printVectorPairs(vector<vector<int>>(result.begin(), result.begin() + expected.size()));
        cout << "\n\n";
    }
}

int main() {
    int passed = 0, total = 0;

    // Test cases
    runTestCase({4, 2, 1, 3}, {{1, 2}, {2, 3}, {3, 4}}, passed, total);
    runTestCase({1, 3, 6, 10, 15}, {{1, 3}}, passed, total);
    runTestCase({3, 8, -10, 23, 19, -4, -14, 27}, {{-14, -10}, {19, 23}, {23, 27}}, passed, total);
    runTestCase({1, 100000}, {{1, 100000}}, passed, total);
    runTestCase({1, 1}, {{1, 1}}, passed, total);
    runTestCase({-1, -2, -3, -4}, {{-4, -3}, {-3, -2}, {-2, -1}}, passed, total);
    runTestCase({100, 200, 300, 400}, {{100, 200}, {200, 300}, {300, 400}}, passed, total);
    runTestCase({0, 5, 10, 15, 20}, {{0, 5}, {5, 10}, {10, 15}, {15, 20}}, passed, total);
    runTestCase({-1000000, 1000000}, {{-1000000, 1000000}}, passed, total);

    // Test 10: Large input, match expected prefix
    vector<int> large(100000);
    iota(large.begin(), large.end(), -50000);
    vector<vector<int>> expectedPrefix = {
        {-50000, -49999},
        {-49999, -49998},
        {-49998, -49997},
        {-49997, -49996},
        {-49996, -49995}
    };
    runTestCase(large, expectedPrefix, passed, total, true);

    cout << "\nPassed " << passed << " / " << total << " test cases.\n";

    return 0;
}
