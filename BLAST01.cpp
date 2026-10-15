#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// A Trie node stores links to the next letters.
struct Node {
    Node* children[26];
    bool isEndOfWord;

    Node() {
        isEndOfWord = false;

        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class Trie {
private:
    Node* root;

    // Convert a letter into an array position.
    // a = 0, b = 1, ..., z = 25
    int index(char ch) {
        return ch - 'a';
    }

    // Display all complete words below a node.
    void displayWords(Node* current, string word) {

        if (current->isEndOfWord) {
            cout << "- " << word << endl;
        }

        for (int i = 0; i < 26; i++) {

            if (current->children[i] != nullptr) {

                char nextLetter = 'a' + i;

                displayWords(
                    current->children[i],
                    word + nextLetter
                );
            }
        }
    }

public:

    // Constructor
    Trie() {
        root = new Node();
    }

    // Insert a word into the Trie.
    void insert(string word) {

        Node* current = root;

        for (char ch : word) {

            int position = index(ch);

            if (current->children[position] == nullptr) {
                current->children[position] = new Node();
            }

            current = current->children[position];
        }

        current->isEndOfWord = true;
    }

    // Search for an exact word.
    bool search(string word) {

        Node* current = root;

        for (char ch : word) {

            int position = index(ch);

            if (current->children[position] == nullptr) {
                return false;
            }

            current = current->children[position];
        }

        return current->isEndOfWord;
    }

    // Find words that start with a prefix.
    void autocomplete(string prefix) {

        Node* current = root;

        // Follow the prefix through the Trie.
        for (char ch : prefix) {

            int position = index(ch);

            if (current->children[position] == nullptr) {

                cout << "No suggestions found." << endl;
                return;
            }

            current = current->children[position];
        }

        cout << "\nSuggestions for \"" << prefix << "\":" << endl;

        displayWords(current, prefix);
    }

    // Display all words stored in the Trie.
    void displayAll() {

        cout << "\nAll stored words:" << endl;

        displayWords(root, "");
    }

    // Remove a word from the Trie.
    //
    // We mark the word as no longer being a complete word.
    // We do not delete the nodes because they may be shared
    // with other words.
    bool remove(string word) {

        Node* current = root;

        // Follow the word through the Trie.
        for (char ch : word) {

            int position = index(ch);

            if (current->children[position] == nullptr) {
                return false;
            }

            current = current->children[position];
        }

        // The path exists, but the complete word does not.
        if (!current->isEndOfWord) {
            return false;
        }

        // Mark the word as removed.
        current->isEndOfWord = false;

        return true;
    }
};


// Convert input to lowercase and check that
// it contains letters only.
bool normalizeWord(string& word) {

    if (word.empty()) {
        return false;
    }

    for (char& ch : word) {

        if (!isalpha(static_cast<unsigned char>(ch))) {
            return false;
        }

        ch = static_cast<char>(
            tolower(static_cast<unsigned char>(ch))
        );
    }

    return true;
}


int main() {

    Trie trie;

    // Starter vocabulary.
    trie.insert("computer");
    trie.insert("compute");
    trie.insert("computing");
    trie.insert("communication");
    trie.insert("community");
    trie.insert("college");
    trie.insert("cloud");
    trie.insert("class");
    trie.insert("coding");
    trie.insert("code");
    trie.insert("coffee");
    trie.insert("camera");

    int choice;

    cout << "========================================" << endl;
    cout << "     TRIE PREDICTIVE TEXT SYSTEM" << endl;
    cout << "========================================" << endl;

    do {

        cout << "\nMENU" << endl;
        cout << "1. Add a word" << endl;
        cout << "2. Search for a word" << endl;
        cout << "3. Autocomplete" << endl;
        cout << "4. Display all words" << endl;
        cout << "5. Remove a word" << endl;
        cout << "6. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;


        // -----------------------------
        // 1. ADD WORD
        // -----------------------------
        if (choice == 1) {

            string word;

            cout << "Enter a word: ";
            cin >> word;

            if (!normalizeWord(word)) {

                cout << "Invalid input. "
                     << "Please use letters only."
                     << endl;

            }
            else {

                trie.insert(word);

                cout << "Word added successfully."
                     << endl;
            }
        }


        // -----------------------------
        // 2. SEARCH WORD
        // -----------------------------
        else if (choice == 2) {

            string word;

            cout << "Enter a word: ";
            cin >> word;

            if (!normalizeWord(word)) {

                cout << "Invalid input. "
                     << "Please use letters only."
                     << endl;
            }
            else if (trie.search(word)) {

                cout << "Word found!" << endl;
            }
            else {

                cout << "Word not found." << endl;
            }
        }


        // -----------------------------
        // 3. AUTOCOMPLETE
        // -----------------------------
        else if (choice == 3) {

            string prefix;

            cout << "Enter a prefix: ";
            cin >> prefix;

            if (!normalizeWord(prefix)) {

                cout << "Invalid input. "
                     << "Please use letters only."
                     << endl;
            }
            else {

                trie.autocomplete(prefix);
            }
        }


        // -----------------------------
        // 4. DISPLAY ALL WORDS
        // -----------------------------
        else if (choice == 4) {

            trie.displayAll();
        }


        // -----------------------------
        // 5. REMOVE WORD
        // -----------------------------
        else if (choice == 5) {

            string word;

            cout << "Enter a word to remove: ";
            cin >> word;

            if (!normalizeWord(word)) {

                cout << "Invalid input. "
                     << "Please use letters only."
                     << endl;
            }
            else if (trie.remove(word)) {

                cout << "Word removed successfully."
                     << endl;
            }
            else {

                cout << "Word was not found."
                     << endl;
            }
        }


        // -----------------------------
        // 6. EXIT
        // -----------------------------
        else if (choice == 6) {

            cout << "Thank you for using "
                 << "the Trie system!"
                 << endl;
        }


        // -----------------------------
        // INVALID MENU CHOICE
        // -----------------------------
        else {

            cout << "Invalid choice. "
                 << "Please select 1-6."
                 << endl;
        }

    } while (choice != 6);


    return 0;
}
