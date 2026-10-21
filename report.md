# Technical Report: Trie-Based Predictive Text and Autocomplete

## 1. Introduction

Data structures are important in computer science because they organize information and make operations such as searching and inserting data more efficient. A Trie is a tree-based data structure designed to store and retrieve strings using their characters.

This project demonstrates a Trie through a menu-based C++ predictive text and autocomplete application. The project connects a traditional data structure to Artificial Intelligence (AI) and Natural Language Processing (NLP).

## 2. How a Trie Works

A Trie stores words as paths through a tree. Each node represents a character, and each path from the root represents a sequence of characters. A Boolean flag indicates whether a node completes a stored word.

For example, the words `car`, `cat`, and `care` share the prefix `ca`. Their common characters can share nodes, while their remaining characters follow different branches.

The program uses an array of 26 child pointers in each node, representing the lowercase English letters a through z.

## 3. Main Operations

### Insertion

Insertion starts at the root and processes each character. If the required child node does not exist, the program creates it. After processing all characters, it marks the final node as the end of a word.

### Searching

Searching follows the character path for the requested word. The word is found only if all characters exist and the final node is marked as the end of a word.

### Autocomplete

Autocomplete follows the characters of the supplied prefix. If the prefix exists, the program explores the subtree below that point and displays the complete words it finds.

### Displaying All Words

The program traverses the Trie and displays every stored word. It visits child nodes in alphabetical order.

### Removing a Word

Removal marks the final node as no longer completing a word. Nodes that are no longer needed can be deleted, but shared prefixes must remain when other words depend on them.

## 4. Time and Space Complexity

Let L be the length of the word or prefix, and let V represent the number of Trie nodes visited during a traversal.

| Operation | Complexity |
|---|---|
| Insert a word | O(L) |
| Search for a word | O(L) |
| Locate an autocomplete prefix | O(L) |
| Generate suggestions | Depends on the subtree traversed and output size |
| Remove a word | O(L) |
| Display all words | Depends on the total Trie size and output |

Each node contains 26 child pointers and an end-of-word flag. Therefore, the implementation has a fixed child-array cost per node. Total memory usage depends on the number of nodes created.

## 5. Connection to AI and Natural Language Processing

Predictive text systems help users enter words more quickly by suggesting possible completions as they type. A Trie can efficiently locate words that share a prefix, making it useful as a vocabulary lookup component in such systems.

In Natural Language Processing, prefix lookup can support text-entry interfaces, dictionary search, and autocomplete features.

This project demonstrates the data-structure component of autocomplete. It does not implement a trained language model, rank suggestions by probability, or understand sentence context.

## 6. Real-World Applications

### Search and Autocomplete

Search boxes can use prefix-based structures to find terms that begin with the characters a user enters.

### Dictionary and Word Lookup

A Trie can organize vocabulary for applications that need to find words or check whether a string exists in a stored word collection.

### Text Processing

Trie-based lookup can support prefix matching and vocabulary operations used in language-related software.

These examples describe general applications of Trie structures; this project does not claim to reproduce a commercial search engine or a complete AI language system.

## 7. Program Design

The program contains a `Node` structure and a `Trie` class.

The `Node` structure stores child pointers and the end-of-word flag. The `Trie` class manages the root node and provides insertion, searching, autocomplete, display, and removal operations.

The `main()` function initializes sample vocabulary and presents a menu that allows the user to choose an operation. Input validation accepts alphabetic words and converts them to lowercase.

## 8. Testing and Edge Cases

The following tests should be performed and documented after running the program:

1. Search for a word that exists in the starter vocabulary.
2. Search for a word that does not exist.
3. Enter the prefix `comp` and inspect the suggestions.
4. Add a new word and search for it.
5. Remove an existing word and confirm that it is no longer found.
6. Attempt to remove a word that does not exist.
7. Test a prefix with no matches.
8. Enter invalid input containing digits or punctuation.

Record the actual outputs observed during testing before submitting the report.

## 9. Limitations

The application uses a small, predefined vocabulary and accepts alphabetic input only. It does not support spaces, punctuation, Unicode characters, automatic learning of language patterns, or context-aware ranking.

A larger vocabulary, frequency-based ranking, and integration with a language model could be considered future improvements.

## 10. Conclusion

This project demonstrates how a Trie organizes words and supports efficient prefix-based lookup. The C++ application provides practical examples of insertion, search, autocomplete, display, and removal. It also illustrates how data structures can contribute to AI and NLP applications without requiring a complete AI system.

## References

1. Course assignment instructions, *Emerging Technologies Through Data Structures in C++*.
2. cppreference.com, C++ language and standard library reference, https://en.cppreference.com/
3. Knuth, D. E., *The Art of Computer Programming, Volume 3: Sorting and Searching*. Addison-Wesley. Consult the relevant sections if using this source in the final submission.
