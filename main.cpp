#include <iostream>
#include <array>
#include <vector>
#include <deque>
#include <string>
#include "Item.h"
#include "ArrayUtils.h"

template <typename Container>
void displayContainer(const Container& container, const std::string& label) {
    std::cout << label << ": ";
    for (const auto& element : container) {
        std::cout << element << " "; 
    }
    std::cout << "\n";
}

int main() {
    // --- ЗАВДАННЯ 1: std::array (Злиття відсортованих контейнерів) ---
    std::cout << "========== ЗАВДАННЯ 1 (std::array) ==========\n";
    
    std::array<Item, 3> arr1 = { 
        Item(1, 10.5, "Флешка"), 
        Item(2, 550.0, "Клавіатура"), 
        Item(3, 4500.0, "Монітор") 
    };
    std::array<Item, 2> arr2 = { 
        Item(4, 150.0, "Мишка"), 
        Item(5, 1200.0, "Навушники") 
    };

    displayContainer(arr1, "Масив 1");
    displayContainer(arr2, "Масив 2");

    // Функція повертає новий відсортований масив розміром N1 + N2
    auto mergedArr = mergeArrays(arr1, arr2);
    displayContainer(mergedArr, "Результат злиття за ціною");
    std::cout << "\n";


    // --- ЗАВДАННЯ 2: std::vector (Розбиття на парні/непарні) ---
    std::cout << "========== ЗАВДАННЯ 2 (std::vector) ==========\n";
    
    std::vector<int> numbers = {10, 15, 22, 33, 40, 5, 8};
    std::vector<int> evens, odds;

    displayContainer(numbers, "Початковий список чисел");

    splitVector(numbers, evens, odds);

    displayContainer(evens, "Парні (evens)");
    displayContainer(odds, "Непарні (odds)");
    std::cout << "\n";


    // --- ЗАВДАННЯ 3: std::deque (Перевірка на паліндром) ---
    std::cout << "========== ЗАВДАННЯ 3 (std::deque) ==========\n";
    
    std::deque<int> palDeque = {1, 2, 3, 2, 1};
    std::deque<int> normalDeque = {1, 2, 3, 4, 5};

    displayContainer(palDeque, "Дек №1");
    std::cout << "Чи є паліндромом: " << (isPalindrome(palDeque) ? "ТАК" : "НІ") << "\n";

    displayContainer(normalDeque, "Дек №2");
    std::cout << "Чи є паліндромом: " << (isPalindrome(normalDeque) ? "ТАК" : "НІ") << "\n";

    return 0;
}