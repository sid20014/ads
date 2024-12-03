#include <iostream>
#include <map>
#include <string>

class SuffixTreeNode {
public:
    std::map<char, SuffixTreeNode*> children; // Map to store child nodes
    int start;  // Start index of the edge
    int* end;   // End index of the edge (pointer for flexibility)

    SuffixTreeNode(int start, int* end) : start(start), end(end) {}
};

class SuffixTree {
private:
    SuffixTreeNode* root; // Root of the suffix tree
    std::string text;     // Input text
    int textLength;       // Length of the text

    // Helper function to print the suffix tree
    void printTree(SuffixTreeNode* node, int level = 0) {
        for (const auto& child : node->children) {
            std::cout << std::string(level * 4, ' '); // Indentation
            std::cout << "'" << text.substr(child.second->start, 
                        *(child.second->end) - child.second->start + 1) << "'\n";
            printTree(child.second, level + 1);
        }
    }

public:
    SuffixTree(const std::string& input) : text(input), textLength(input.length()) {
        root = new SuffixTreeNode(-1, new int(-1)); // Root node
        buildSuffixTree();
    }

    ~SuffixTree() {
        deleteTree(root);
    }

    // Function to delete the tree recursively
    void deleteTree(SuffixTreeNode* node) {
        for (auto& child : node->children) {
            deleteTree(child.second);
        }
        delete node->end;
        delete node;
    }

    // Function to build the suffix tree
    void buildSuffixTree() {
        for (int i = 0; i < textLength; ++i) {
            extendSuffixTree(i);
        }
    }

    // Extend the suffix tree for the ith suffix
    void extendSuffixTree(int pos) {
        SuffixTreeNode* currentNode = root;
        for (int i = pos; i < textLength; ++i) {
            char currentChar = text[i];
            if (currentNode->children.find(currentChar) == currentNode->children.end()) {
                // If the current character is not present, create a new node
                currentNode->children[currentChar] = new SuffixTreeNode(i, new int(textLength - 1));
            }
            currentNode = currentNode->children[currentChar];
        }
    }

    // Print the suffix tree
    void print() {
        std::cout << "Suffix Tree Structure:\n";
        printTree(root);
    }
};

int main() {
    std::string input = "banana";
    SuffixTree tree(input);
    tree.print();
    return 0;
}

