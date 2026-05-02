#pragma once
#include <iostream>
#include <array>
#include <cstddef>

template <typename T, std::size_t N1, std::size_t N2>
std::array<T, N1 + N2> mergeArrays(const std::array<T, N1>& arr1, const std::array<T, N2>& arr2){
    std::array<T, N1 + N2> mergedArray;
    auto it1 = arr1.begin();
    auto it2 = arr2.begin();
    auto itMerged = mergedArray.begin();

    while (it1 != arr1.end() && it2 != arr2.end()) {
        if (*it1 < *it2) {
            *itMerged = *it1;
            ++it1;
            ++itMerged;
        } else {
            *itMerged = *it2;
            ++it2;
            ++itMerged;
        }
    } while (it1 != arr1.end()) {
        *itMerged = *it1;
        ++it1;
        ++itMerged;
    } while (it2 != arr2.end()) {
        *itMerged = *it2;
        ++it2;
        ++itMerged;
    } return mergedArray;
}