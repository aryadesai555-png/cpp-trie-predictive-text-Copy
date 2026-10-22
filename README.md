# cpp-trie-predictive-text-Copy
A C++ Trie-based predictive text and autocomplete system demonstrating applications in AI and Natural Language Processing (NLP).  Copy description
# Trie-Based Predictive Text and Autocomplete System

## Project Overview

This project is a menu-based C++ application demonstrating how a Trie data structure supports predictive text and autocomplete. It connects data structures to Artificial Intelligence (AI) and Natural Language Processing (NLP).

## Objectives

- Understand how a Trie stores and organizes words.
- Implement word insertion, searching, autocomplete, and removal.
- Demonstrate how prefix searching supports predictive text systems.
- Explore the role of data structures in AI and NLP.

## What Is a Trie?

A Trie is a tree-like data structure used to store strings. Each node represents a character, and paths through the tree represent words or word prefixes.

This project uses a Trie to find words beginning with a specified prefix.

## Features

1. Add a word.
2. Search for a word.
3. Generate autocomplete suggestions.
4. Display all stored words.
5. Remove a word.
6. Exit the application.

## Technologies Used

- **Programming language:** C++
- **Data structure:** Trie
- **Emerging technology area:** Artificial Intelligence / Natural Language Processing

## How to Compile and Run

Install a C++ compiler first.

Compile the program:

```bash
g++ -std=c++17 BLAST01.cpp -o trie
```

Run on macOS or Linux:

```bash
./trie
```

On Windows, run the generated executable:

```bash
trie.exe
```

## Example

The application starts with sample words, including `computer`, `compute`, `computing`, `cloud`, and `coding`.

Entering the prefix `comp` should return matching stored words.

## Time and Space Complexity

Let **L** represent the length of a word or prefix.

- Insertion: O(L)
- Exact search: O(L)
- Prefix traversal: O(L), excluding the time required to display suggestions
- Space: Depends on the number of Trie nodes and their child pointers

## Repository Contents

- `BLAST01.cpp` — C++ source code
- `README.md` — Project documentation

## References

- Course assignment: *Emerging Technologies Through Data Structures in C++*.
- C++ reference documentation: https://en.cppreference.com/

## Project Links

- **GitHub:** This repository
- **YouTube presentation:** https://youtu.be/2bZTXe7q0gA
- **LinkedIn post:** https://www.linkedin.com/in/arya-desai-7492b3359/
