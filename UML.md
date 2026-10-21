# UML and Design Documentation

## 1. System Overview

The Trie Predictive Text and Autocomplete System is a menu-based C++ application. It stores words in a Trie and provides operations for adding, searching, suggesting, displaying, and removing words.

## 2. Class Design

### Node Structure

**Attributes**
- `children[26]`: Array of pointers to child nodes representing letters a–z.
- `isEndOfWord`: Boolean indicating whether the current node completes a word.

### Trie Class

**Private attributes**
- `root`: Pointer to the root node.

**Private methods**
- `index(char ch)`: Converts a lowercase letter into an array index.
- `displayWords(Node* current, string word)`: Traverses the Trie and displays complete words.
- `removeWord(Node* current, string word, int depth, bool& found)`: Recursively removes a word and prunes unnecessary nodes.

**Public methods**
- `Trie()`: Creates the root node.
- `insert(string word)`: Inserts a word.
- `search(string word)`: Searches for an exact word.
- `autocomplete(string prefix)`: Displays words matching a prefix.
- `displayAll()`: Displays all stored words.
- `remove(string word)`: Removes a word.

### Main Function

The `main()` function initializes sample words, displays the menu, accepts the user's choice, validates input, and calls the appropriate Trie operation.

## 3. UML Class Diagram

```mermaid
classDiagram
    class Node {
        +Node* children[26]
        +bool isEndOfWord
    }

    class Trie {
        -Node* root
        -int index(char ch)
        -void displayWords(Node* current, string word)
        -bool removeWord(Node* current, string word, int depth, bool& found)
        +Trie()
        +void insert(string word)
        +bool search(string word)
        +void autocomplete(string prefix)
        +void displayAll()
        +bool remove(string word)
    }

    Trie *-- Node : contains
    Node --> Node : child pointers
```

## 4. Program Flow

```mermaid
flowchart TD
    A([Start]) --> B[Create Trie]
    B --> C[Insert starter words]
    C --> D[Display menu]
    D --> E{User choice}
    E -->|1| F[Validate and insert word]
    E -->|2| G[Validate and search word]
    E -->|3| H[Validate prefix and autocomplete]
    E -->|4| I[Display all words]
    E -->|5| J[Validate and remove word]
    F --> D
    G --> D
    H --> D
    I --> D
    J --> D
    E -->|6| K([Exit])
```

## 5. Design Explanation

The `Trie` class manages the word-storage structure, while each `Node` stores character links and information about completed words. The root represents the beginning of all stored words.

The menu separates user interaction from the core Trie operations. Input normalization converts alphabetic input to lowercase and rejects empty strings or characters outside the accepted alphabet.

## 6. Relationship to Predictive Text

When a user enters a prefix, the program follows the corresponding character path. If the path exists, it traverses the remaining subtree to display words beginning with that prefix. This demonstrates the basic lookup mechanism used by autocomplete features.

## 7. Design Limitations

The implementation supports lowercase English letters after input normalization. It uses a fixed array of 26 child pointers for every node. It demonstrates prefix matching but does not rank suggestions using word frequency or contextual language predictions.
