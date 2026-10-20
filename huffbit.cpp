#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <string>
#include <iomanip>
#include <memory>
#include <limits>
using namespace std;

struct Node {
    unsigned char ch;
    long long freq;
    Node *left, *right;
    Node(unsigned char c, long long f, Node* l = nullptr, Node* r = nullptr)
        : ch(c), freq(f), left(l), right(r) {}
};

struct Compare {
    bool operator()(const Node* a, const Node* b) const {
        if (a->freq == b->freq) return a->ch > b->ch;
        return a->freq > b->freq;
    }
};

void buildCodes(Node* root, const string& path, unordered_map<unsigned char, string>& codes) {
    if (!root) return;
    if (!root->left && !root->right) {
        codes[root->ch] = path.empty() ? "0" : path;
        return;
    }
    buildCodes(root->left, path + "0", codes);
    buildCodes(root->right, path + "1", codes);
}

void deleteTree(Node* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

string showCharacter(unsigned char c) {
    if (c == ' ') return "[space]";
    if (c == '\n') return "[newline]";
    if (c == '\t') return "[tab]";
    if (c == '\r') return "[carriage return]";
    return string(1, static_cast<char>(c));
}

int main() {
    cout << "====================================================\n";
    cout << "       HUFFBIT: SMART TEXT COMPRESSION ANALYZER\n";
    cout << "====================================================\n";
    cout << "Enter a line of text to compress:\n> ";

    string input;
    getline(cin, input);
    if (input.empty()) {
        cout << "\nNo text was entered. Please run the program again with non-empty text.\n";
        return 0;
    }

    unordered_map<unsigned char, long long> frequency;
    for (unsigned char c : input) frequency[c]++;

    priority_queue<Node*, vector<Node*>, Compare> pq;
    for (const auto& item : frequency)
        pq.push(new Node(item.first, item.second));

    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();
        pq.push(new Node(0, left->freq + right->freq, left, right));
    }

    Node* root = pq.top();
    unordered_map<unsigned char, string> codes;
    buildCodes(root, "", codes);

    string encoded;
    for (unsigned char c : input) encoded += codes[c];

    string decoded;
    if (!root->left && !root->right) {
        decoded.assign(input.size(), static_cast<char>(root->ch));
    } else {
        Node* current = root;
        for (char bit : encoded) {
            current = (bit == '0') ? current->left : current->right;
            if (current && !current->left && !current->right) {
                decoded += static_cast<char>(current->ch);
                current = root;
            }
        }
    }

    cout << "\n1. CHARACTER FREQUENCY TABLE\n";
    cout << left << setw(20) << "Character" << "Frequency\n";
    cout << "--------------------------------\n";
    vector<pair<unsigned char, long long>> sortedFreq(frequency.begin(), frequency.end());
    sort(sortedFreq.begin(), sortedFreq.end(), [](const auto& a, const auto& b) { return a.first < b.first; });
    for (const auto& item : sortedFreq)
        cout << left << setw(20) << showCharacter(item.first) << item.second << "\n";

    cout << "\n2. HUFFMAN CODE TABLE\n";
    cout << left << setw(20) << "Character" << setw(15) << "Frequency" << "Huffman Code\n";
    cout << "----------------------------------------------------\n";
    for (const auto& item : sortedFreq)
        cout << left << setw(20) << showCharacter(item.first)
             << setw(15) << item.second << codes[item.first] << "\n";

    cout << "\n3. ENCODED BINARY BITSTREAM\n";
    cout << encoded << "\n";

    const long long originalBits = static_cast<long long>(input.size()) * 8;
    const long long encodedBits = static_cast<long long>(encoded.size());
    const double ratio = encodedBits == 0 ? 0.0 : static_cast<double>(originalBits) / encodedBits;
    const double reduction = originalBits == 0 ? 0.0 : (1.0 - static_cast<double>(encodedBits) / originalBits) * 100.0;

    cout << "\n4. DECODED TEXT\n";
    cout << decoded << "\n";
    cout << "Decoding check: " << (decoded == input ? "PASS - decoded text matches original" : "FAIL") << "\n";

    cout << "\n5. BINARY STORAGE ANALYSIS\n";
    cout << "Original text length       : " << input.size() << " characters\n";
    cout << "Distinct characters        : " << frequency.size() << "\n";
    cout << "Original text size         : " << originalBits << " bits (8 bits per character)\n";
    cout << "Encoded payload size       : " << encodedBits << " bits (excluding tree/code-table metadata)\n";
    cout << fixed << setprecision(2);
    if (encodedBits > 0)
        cout << "Payload compression ratio  : " << ratio << ":1 (original bits / encoded bits)\n";
    cout << "Payload size reduction     : " << reduction << "%\n";
    if (encodedBits < originalBits)
        cout << "Result                     : Encoded payload is smaller than the original text.\n";
    else if (encodedBits == originalBits)
        cout << "Result                     : Encoded payload has the same size as the original text.\n";
    else
        cout << "Result                     : Encoded payload is larger for this input.\n";
    cout << "Note: Actual stored files also need code/tree metadata and may need padding.\n";

    deleteTree(root);
    return 0;
}
