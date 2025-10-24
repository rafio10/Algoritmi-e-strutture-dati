#include <iostream>
#include <string>

bool isSafe(const std::string& str, int left, int index) {
    for (int i = left; i < index; i++) {
        if (str[i] == str[index]) {
            return false;
        }
    }
    return true;
}

void generatePermutations(std::string& str, int left, int right) {
    if (left == right) {
        std::cout << str << std::endl; // Stampa la permutazione corrente
        return;
    }

    for (int i = left; i <= right; i++) {
        if (isSafe(str, left, i)) {
            std::swap(str[left], str[i]); // Scambia i caratteri
            generatePermutations(str, left + 1, right); // Genera le permutazioni rimanenti
            std::swap(str[left], str[i]); // Ripristina lo stato originale
        }
    }
}

int main() {
    std::string input;
    std::cout << "Inserisci una stringa: ";
    std::cin >> input;

    int n = input.length();

    std::cout << "Permutazioni di " << input << ":" << std::endl;
    generatePermutations(input, 0, n - 1);

    return 0;
}
