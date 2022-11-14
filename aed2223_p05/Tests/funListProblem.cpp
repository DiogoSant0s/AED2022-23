#include "funListProblem.h"
#include <algorithm>

FunListProblem::FunListProblem() = default;

//-----------------------------------------------------------------

// TODO
list<int> FunListProblem::removeHigher(list<int> &values, int x) {
    list<int> l1;
    for (auto it = values.begin(); it != values.end(); it++) {
        if (*it > x) {
            l1.push_back(*it);
            it = values.erase(it);
            it--;
        }
    }
    return l1;
}

//TODO
list<pair<int, int>> FunListProblem::overlappingIntervals(list<pair<int, int>> &values) {
    list<pair<int,int>> res;
    values.sort();
    auto it = values.begin();
    int f = it -> first, s = it -> second;
    it++;
    while (it != values.end()) {
        if (s < it -> first) {
            res.emplace_back(f, s);
            f = it -> first;
            s = it -> second;
        }
        else if (s < it -> second) {
            s = it -> second;
        }
        it++;
    }
    res.emplace_back(f, s);
    return res;

}
