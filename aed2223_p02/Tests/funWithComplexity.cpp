// AED 2022/2023 - Aula Pratica 02
// Pedro Ribeiro (DCC/FCUP) [ultimo update: 25/09/2022]

#include "funWithComplexity.h"

// ----------------------------------------------------------
// Exercicio 4: Sequencias
// ----------------------------------------------------------
// TODO

int FunWithComplexity::maxSubArray(const vector<int> & v) {
    unsigned n = v.size();
    int best_sum = INT16_MIN;
    int current_sum = 0;
    for (int i = 0; i < n; i++) {
        current_sum = max(v[i], current_sum + v[i]);
        best_sum = max(best_sum, current_sum);
    }
    return best_sum;

}

// ----------------------------------------------------------
// Exercicio 5: Analisando um rio
// ----------------------------------------------------------
// TODO
int FunWithComplexity::river(const vector<int> & v, int k, int t) {
    int r = 0;
    int c = 0;
    for (int i = 0; i < k; i++) {
        if (v[i] >= t) {c += 1;}
    }
    if (c > k / 2 && k % 2 != 0) {r += 1;}
    else if (c >= k / 2 && k % 2 == 0) {r += 1;}

    for (int j = k; j < v.size(); j++) {
        if (v[j] >= t) {c += 1;}
        if (v[j - k] >= t) {c -= 1;}
        if (c > k / 2 && k % 2 != 0) {r += 1;}
        else if (c >= k / 2 && k % 2 == 0) {r += 1;}
    }
    return r;
}

// ----------------------------------------------------------
// Exercicio 6: Espiral de Números
// ----------------------------------------------------------
// TODO

pair<int, int> FunWithComplexity::spiral(int n) {
    pair<int, int> ans = {0, 0};

    return ans;
}

// ----------------------------------------------------------
// Exercicio 8: Caderno Quadriculado
// ----------------------------------------------------------
// TODO

long long FunWithComplexity::gridSum(int a, int b) {

    return 0;
}