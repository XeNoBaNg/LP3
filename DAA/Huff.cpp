#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;

struct HuffmanNode {
    char data;                  // Input character
    int frequency;              // Frequency of the character
    HuffmanNode *left, *right;  // Left and right children

    HuffmanNode(char data, int frequency) {
        left = right = nullptr;
        this->data = data;
        this->frequency = frequency;
    }
};

// Comparator to order the min-heap (priority queue)
struct Compare {
    bool operator()(HuffmanNode* left, HuffmanNode* right) {
        return left->frequency > right->frequency;
    }
};

// Function to print the Huffman codes
void printCodes(HuffmanNode* root, string code, unordered_map<char, string>& huffmanCodes) {
    if (!root) return;

    // If this node is a leaf node, it contains a character
    if (!root->left && !root->right) {
        huffmanCodes[root->data] = code;
        cout << root->data << ": " << code << endl;
    }

    // Traverse left and right subtrees
    printCodes(root->left, code + "0", huffmanCodes);
    printCodes(root->right, code + "1", huffmanCodes);
}

// Function to build the Huffman tree and print codes
void buildHuffmanTree(const string& text) {
    // Count the frequency of each character
    unordered_map<char, int> frequencyMap;
    for (char ch : text) {
        frequencyMap[ch]++;
    }

    // Create a priority queue (min-heap)
    priority_queue<HuffmanNode*, vector<HuffmanNode*>, Compare> pq;

    // Create a leaf node for each character and add it to the priority queue
    for (auto pair : frequencyMap) {
        pq.push(new HuffmanNode(pair.first, pair.second));
    }

    // Iterate until there is only one node left in the priority queue
    while (pq.size() > 1) {
        // Remove two nodes of the highest priority (lowest frequency)
        HuffmanNode* left = pq.top();
        pq.pop();
        HuffmanNode* right = pq.top();
        pq.pop();

        // Create a new internal node with frequency equal to the sum of the two nodes' frequencies
        HuffmanNode* newNode = new HuffmanNode('\0', left->frequency + right->frequency);

        newNode->left = left;
        newNode->right = right;

        // Add the new node to the priority queue
        pq.push(newNode);
    }

    // The remaining node is the root of the Huffman tree
    HuffmanNode* root = pq.top();

    // Traverse the Huffman tree and store the codes in a map
    unordered_map<char, string> huffmanCodes;
    printCodes(root, "", huffmanCodes);

    // Print the encoded string
    cout << "\nEncoded string: ";
    for (char ch : text) {
        cout << huffmanCodes[ch];
    }
    cout << endl;
}

int main() {
    string text;
    cout << "Enter text to encode using Huffman Encoding: ";
    getline(cin, text);

    buildHuffmanTree(text);

    return 0;
}
/*
================================================================================
THEORETICAL CONCEPTS, HOW TO RUN & HOW TO EXPLAIN
================================================================================
1. THEORETICAL CONCEPTS:
   - Problem Statement: Lossless data compression using variable-length prefix codes.
   - Greedy Choice Property: Characters with higher frequencies get shorter binary codes,
     while characters with lower frequencies get longer binary codes.
   - Prefix Rule: No code is a prefix of another code, ensuring unambiguous decoding without delimiters.
   - Priority Queue (Min-Heap): Repeatedly extracts the two lowest-frequency nodes,
     combines their frequencies into a parent node, and re-inserts into the min-heap.
   - Time Complexity:
     * Frequency counting: O(n) where n is text length.
     * Building Tree     : O(k log k) where k is the number of unique characters.
     * Code Generation   : O(k).
     * Total Time        : O(n + k log k).
   - Space Complexity    : O(k) for heap and tree nodes.

2. HOW TO RUN:
   - Compile: g++ Huff.cpp -o Huff
   - Run    : ./Huff        (Linux/macOS) or Huff.exe (Windows)
   - Input  : Enter any text string when prompted (e.g., "aabbbcccc").

3. HOW TO EXPLAIN TO THE EXAMINER (30-SECOND VIVA PITCH):
   "Sir/Madam, this program implements Huffman Encoding using a Greedy Algorithm:
   - First, we count character frequencies using a hash map (unordered_map).
   - We place each character as a leaf node in a min-heap priority queue.
   - In each greedy step, we extract the two nodes with minimum frequencies, combine them
     under an internal parent node with their sum, and push it back into the heap.
   - When only one node remains, it becomes the root of the Huffman Tree.
   - By traversing left with '0' and right with '1', we assign prefix codes and encode the string.
   - Total time complexity is O(n + k log k) where k is unique characters."

4. COMMON VIVA QUESTIONS:
   Q: Why is it called a prefix code?
   A: Because no character's assigned code is a prefix of another character's code, so we can
      decode greedily without separators.
   Q: Which data structure is used to build the tree?
   A: A Min-Heap (std::priority_queue with a custom greater comparator).
================================================================================
*/
