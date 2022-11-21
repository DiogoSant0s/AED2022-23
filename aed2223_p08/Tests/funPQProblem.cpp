#include "funPQProblem.h"

FunPQProblem::FunPQProblem() = default;


//-----------------------------------------------------------------

// TODO
int FunPQProblem::minCost(const vector<int> &ropes) {
    int r = 0;
    int f, s;
    priority_queue<int> queue;
    for (const int& i : ropes) {
        queue.push(-i);
    }
    while (queue.size() > 1) {
        f = queue.top();
        queue.pop();
        s = queue.top();
        queue.pop();
        r += f + s;
        queue.push(f + s);
    }
    return -r;
}

