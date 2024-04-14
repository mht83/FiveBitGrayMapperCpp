//////////////////////////////////////////////written by mht83/////////////////////////////////////////
#include <iostream>
#include <string>
#include <bitset>

// ANSI color codes for terminal output
const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string YELLOW = "\033[33m";
const std::string BLUE = "\033[34m";
const std::string RESET = "\033[0m";

std::string binaryToGray(std::string binary) {
    std::string gray = "";
    gray += binary[0];

    for (size_t i = 1; i < binary.length(); i++) {
        gray += (binary[i - 1] == binary[i]) ? '0' : '1';
    }
    return gray;
}


std::string grayToBinary(std::string gray) {
    std::string binary = "";
    binary += gray[0];

    for (size_t i = 1; i < gray.length(); i++) {
        binary += (binary[i - 1] == gray[i]) ? '0' : '1';
    }
    return binary;
}

int main() {
    std::cout << GREEN << "Welcome to the 5-bit Gray Code Generator!" << RESET << "\n";
    std::cout << "This program displays the binary representations, Gray code representations,\n";
    std::cout << "and decoded Gray code values for all 5-bit numbers.\n\n";

    std::cout << BLUE << "Binary\tGray\tDecoded" << RESET << "\n";
    for (int i = 0; i < 32; ++i) {
        std::string binary = std::bitset<5>(i).to_string();
        std::string gray = binaryToGray(binary);
        std::string decoded = grayToBinary(gray);
        std::cout << YELLOW << binary << "\t" << RESET;
        std::cout << RED << gray << "\t" << RESET;
        std::cout << GREEN << decoded << RESET << "\n";
    }
    return 0;
}