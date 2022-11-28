#include "funHashingProblem.h"
#include <unordered_set>

FunHashingProblem::FunHashingProblem() = default;

// -------------------------------------

// TODO
vector<int> FunHashingProblem::findDuplicates(const vector<int>& values, int k) {
    vector<int> res;
    unordered_set<int> set;
    for (unsigned int i = 0; i < values.size(); i++) {
        if (set.find(values[i]) != set.end()) {
            res.push_back(values[i]);
        }
        set.insert(values[i]);
        if (i >= k) {
            set.erase(values[i - k]);
        }
    }
    return res;
}