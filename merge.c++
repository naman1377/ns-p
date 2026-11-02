#include <iostream>
#include <vector>

// Merge two sorted subarrays vec[l..mid] and vec[mid+1..r]
void merge(std::vector<int>& vec, int l, int mid, int r) {
    int n1 = mid - l + 1;
    int n2 = r - mid;
    std::vector<int> L(vec.begin() + l, vec.begin() + mid + 1);
    std::vector<int> R(vec.begin() + mid + 1, vec.begin() + r + 1);

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) vec[k++] = L[i++];
        else              vec[k++] = R[j++];
    }
    while (i < n1) vec[k++] = L[i++];
    while (j < n2) vec[k++] = R[j++];
}

// Recursively sort vec[l..r] using Merge Sort
void mergeSort(std::vector<int>& vec, int l, int r) {
    if (l < r) {
        int mid = l + (r - l) / 2;
        mergeSort(vec, l, mid);
        mergeSort(vec, mid + 1, r);
        merge(vec, l, mid, r);
    }
}

int main() {
    std::vector<int> vec = {12, 11, 13, 5, 6, 7};
    mergeSort(vec, 0, vec.size() - 1);
    for (int x : vec) std::cout << x << " ";
    std::cout << "\n";
    return 0;
}

// g++ merge.c++ -o merge.exe
