# Cyclic Shift Hashcode Analysis

This C++ program reads a text file, generates cyclic shift hash codes for words, and detects collisions. 

## Purpose

The program aims to illustrate how a cyclic shift hash function works and how collisions occur when different words produce the same hash code.

## Implementation

### Hash Function
The code defines a `HashCode` class with a cyclic shift hash function. The hash code is generated by performing bitwise cyclic shift operations on characters and summing their ASCII values.

### Lowercasing Function
A `lowerCase` function converts input strings to lowercase to ensure consistent hashing irrespective of character case.

### File Reading and Collision Detection
- The program reads a text file, creates hash codes for words, and detects collisions in a provided text file.
- It uses an `unordered_map` to track collisions and word occurrences with their corresponding hash codes.

### Execution
- Compile the code using a C++ compiler (e.g., g++).
- Execute the compiled program, providing a text file path as a command-line argument.

## How to Use

### Compilation
```bash
g++ -o cyclic_hash_analysis cyclic_hash_analysis.cpp
```

### Execution
```bash
./cyclic_hash_analysis C:/Users/jesus/Documents/GitHub/Hash-Map/usdeclarPC.txt
```

Replace `C:/Users/jesus/Documents/GitHub/Hash-Map/usdeclarPC.txt` with the path to the text file to analyze.

## Code Author

- **Author:** Jesus Rodriguez-Luna

## Notes

The collision count might vary based on the hash function and the nature of the text data. A high collision count indicates that different words produce the same hash code, causing collisions.