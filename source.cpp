#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <unordered_map>
#include <cctype>

// Hashcodes
class HashCode {
public:
    // Cyclic shift hash codes
    int operator() (const std::string& s, int a = 37) {
        unsigned int h = 0;

        // Loop through each character in the string to generate a hash code
        for(int i = 0; i < s.size(); i++) {
            // Bitwise cyclic shift operations to create the hash
            h = (h << 5) | (h >> a);
            h += (unsigned int) s[i]; // Add the ASCII value of the character to the hash
        }

        return static_cast<int>(h); // Return the resulting hash code
    }
};

// Function to convert a string to lowercase
std::string lowerCase(std::string& s) {
    std::string word = s;
    for(char& c : s){
        c = std::tolower(c); // Convert each character to lowercase
    }

    return s; // Return the modified string in lowercase
}

int main(int argc, char const *argv[]) {
    std::cout << "Author: Jesus Rodriguez-Luna" << std::endl;

    // Initialize unordered maps to track collisions and word occurrences with their hash codes
    std::unordered_map<int, int> collisions; // Tracks the number of collisions for each hash
    std::unordered_map<int, std::string> wordList; // Tracks the words and their respective hash codes

    // Open the input text file for reading
    std::ifstream US_DoI_File("C:/Users/jesus/Documents/GitHub/Hash-Map/usdeclarPC.txt");
    HashCode h; // Create an instance of the HashCode class for generating hash codes
    int hasher = 0; // Variable to hold the hash code of a word
    std::string word = ""; // Variable to hold each word from the file
    int sumOfCollisions = 0; // Sum of all collision counts

    // Check if the file is not open
    if (!US_DoI_File.is_open())
        std::cout << "Not Open!" << std::endl;

    // Read each word from the file, generate hash codes, and handle collisions
    while (US_DoI_File >> word) {
        hasher = std::abs(h(lowerCase(word))); // Generate hash code for the word in lowercase

        // If the hash doesn't exist in the wordList, add it with the word and initialize collision count
        if (wordList.find(hasher) == wordList.end()) {
            wordList[hasher] = word;
            collisions[hasher] = 1;
        } else {
            // If a collision is detected, increment the collision count for that hash
            if (wordList[hasher] != word) {
                int& collisionCount = collisions[hasher];
                collisionCount++;
            }
        }
    }

    // Calculate the total number of collisions
    auto q = collisions.begin();
    while (q != collisions.end()) {
        if (q->second > 1)
            sumOfCollisions += q->second;
        ++q;
    }

    // Output the total number of collisions detected
    std::cout << "Cyclic Shift Hashcode - Number of collisions: " << sumOfCollisions << std::endl;

    return 0;
}
