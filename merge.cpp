#include <iostream>
#include <vector>
#include <cmath>
using vec = std::vector<int>;

void merge_sort(vec& v){
    if (v.size() > 1) {
        int mid = floor(v.size() / 2);
        vec leftHalf(0), rightHalf(0);

        for(int i = 0; i < mid; ++i)
            leftHalf.push_back(v[i]);

        for (int i = mid; i < v.size(); ++i)
            rightHalf.push_back(v[i]);

        merge_sort(leftHalf);
        merge_sort(rightHalf);

        int i{0},j{0},k{0};

        while(i < leftHalf.size() && j < rightHalf.size()) {
            if (leftHalf[i] < rightHalf[j]) {
                v[k] = leftHalf[i];
                ++i;
            }
            else {
                v[k] = rightHalf[j];
                ++j;
            }
            ++k;
        }

        while(i < leftHalf.size()) {
            v[k] = leftHalf[i];
            ++i;
            ++k;
        }

        while(j < rightHalf.size()) {
            v[k] = rightHalf[j];
            ++j;
            ++k;
        }
    }
}

int main() {
    std::vector<int> toSort {6,5,7,4,8,3,9,2,1,0};
    merge_sort(toSort);
    for(auto num : toSort) { std::cout << num << std::endl;}
    return 0;
}
