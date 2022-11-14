#include "funSortProblem.h"
#include <algorithm>
#include <limits.h>

FunSortProblem::FunSortProblem() {}

//-----------------------------------------------------------------

// TODO
bool compare(const Product &p1, const Product &p2) {
    if (p1.getPrice() != p2.getPrice()) {
        return p1.getPrice() < p2.getPrice();
    }
    return p1.getWeight() < p2.getWeight();
}

void FunSortProblem::expressLane(vector<Product> &products, unsigned k) {
    if (products.size() < k) {return;}
    sort(products.begin(), products.end(), compare);
    products.erase(products.begin() + k, products.end());
}

// TODO
int FunSortProblem::minDifference(const vector<unsigned> &values, unsigned nc) {
    if (values.size() < nc) return -1;
    vector<unsigned> choc = values;
    sort(choc.begin(), choc.end());
    int n = INT32_MAX;
    for (int i = 0; i + nc - 1 < values.size(); i++) {
        if (choc[i + nc - 1] - choc[i] < n) n = choc[i + nc - 1] - choc[i];
    }
    return n;
}

// TODO
unsigned FunSortProblem::minPlatforms (const vector<float> &arrival, const vector<float> &departure) {

    return 0;
}

//TODO
unsigned FunSortProblem::numInversions(vector <int> v) {

    return 0;
}

// TODO
void FunSortProblem::nutsBolts(vector<Piece> &nuts, vector<Piece> &bolts) {

}

