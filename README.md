# HuffBit — Smart Text Compression and Binary Storage Analyzer

HuffBit is a C++17-based text compression project that demonstrates how **Huffman Coding** can reduce the number of bits required to represent text. It also analyzes binary representation and compares the original text size with the encoded payload size.

The project integrates concepts from **Design and Analysis of Algorithms (DAA)** and **Computer Organization and Architecture (COA)** into one practical application.

## 🎯 Objectives

- Implement Huffman Coding using a greedy algorithm.
- Calculate the frequency of each character in the input text.
- Generate variable-length binary codes based on character frequencies.
- Encode text into a binary bitstream.
- Decode the encoded bitstream to reconstruct the original text.
- Compare original and encoded payload sizes.
- Calculate compression ratio and percentage size reduction.
- Verify the correctness of the encoding and decoding process.

## 📚 Concepts Implemented

### 1. Design and Analysis of Algorithms (DAA)

**Concept: Huffman Coding**

Huffman Coding is a greedy algorithm used for lossless data compression. It assigns shorter binary codes to more frequent characters and longer codes to less frequent characters.

The implementation demonstrates:

- Character-frequency analysis.
- Priority queue-based Huffman tree construction.
- Binary code generation through tree traversal.
- Text encoding and decoding.
- Time and space complexity analysis.

### 2. Computer Organization and Architecture (COA)

**Concept: Number Systems and Binary Representation**

Computers represent and process information using binary digits (`0` and `1`). HuffBit demonstrates how text can be represented as an encoded binary sequence and how its payload size can be measured in bits.

The implementation demonstrates:

- Binary representation of encoded text.
- Original text size calculation using 8 bits per character.
- Encoded payload size calculation.
- Compression ratio and percentage size reduction.
- Comparison of original and encoded data sizes.

## ⚙️ Technologies Used

- **Language:** C++
- **Standard:** C++17
- **Data Structure:** Priority Queue
- **Algorithm:** Huffman Coding
- **Compiler:** GCC or Clang
- **Development Environment:** Visual Studio Code or any C++ IDE

## 🛠️ Getting Started

### Prerequisites

Install a C++ compiler that supports C++17.

On macOS, you can install Apple's command-line developer tools using:

```bash
xcode-select --install
```

Verify your compiler installation:

```bash
g++ --version
```

### Installation and Execution

**1. Clone the repository**

Replace `YOUR_USERNAME` and `YOUR_REPOSITORY` with your GitHub username and repository name.

```bash
git clone https://github.com/YOUR_USERNAME/YOUR_REPOSITORY.git
```

**2. Navigate to the project directory**

```bash
cd YOUR_REPOSITORY
```

**3. Compile the program**

```bash
g++ -std=c++17 huffbit.cpp -o huffbit
```

**4. Run the program**

```bash
./huffbit
```

**5. Enter your text**

When prompted, enter the text you want to analyze. For example:

```text
BANANA
```

The program will display the character frequencies, generated Huffman codes, encoded bitstream, decoded text, and storage statistics.

## 🧪 Testing

The program can be tested using inputs such as:

| Test Case | Input | Purpose |
|---|---|---|
| Basic input | `BANANA` | Verify encoding and decoding |
| Repeated character | `AAAAAA` | Test a single distinct character |
| Unique characters | `ABCDE` | Examine frequency distribution |
| Sentence | `Hello World!` | Test spaces and punctuation |
| Longer text | A longer paragraph | Examine compression behaviour |

The decoded text should match the original input for successful lossless reconstruction. Record the actual output of each test after running the program.

## 📊 Compression Metrics

HuffBit uses the following measurements:

**Original size**

For input containing \(n\) characters, assuming 8 bits per character:

`Original Size = n × 8 bits`

**Encoded payload size**

The total number of bits in the generated Huffman bitstream.

**Compression ratio**

`Compression Ratio = Original Size / Encoded Payload Size`

**Percentage size reduction**

`Size Reduction (%) = ((Original Size − Encoded Payload Size) / Original Size) × 100`

These calculations compare the original text representation with the encoded payload only. They do not include the Huffman tree, code table, headers, or padding that a complete compressed file may require. Therefore, the encoded payload can be smaller even when the total stored file would not be smaller.

## ⏱️ Complexity Analysis

Let:

- `n` = number of characters in the input.
- `k` = number of distinct characters.

The typical time complexity of Huffman tree construction is:

`O(n + k log k)`

This includes frequency counting and priority-queue-based tree construction. Encoding and decoding additionally require time proportional to the input or encoded bitstream length, respectively.

The implementation also stores the Huffman tree, character codes, input, and encoded output in memory.

## 📁 Project Structure

```text
HuffBit/
├── huffbit.cpp
└── README.md
```

## 🚀 Future Enhancements

- Develop a graphical user interface for easier interaction.
- Add support for reading and compressing text files.
- Save encoded data and decoding metadata to a file.
- Compare Huffman Coding with other compression algorithms.
- Visualize the Huffman tree and encoding process.
- Measure complete compressed-file size, including metadata and padding.

## 🎓 Academic Context

This project is developed as an integrated micro project for:

- **Design and Analysis of Algorithms (DAA)**
- **Computer Organization and Architecture (COA)**

**Project Title:** HuffBit — Smart Text Compression and Binary Storage Analyzer  
**Student:** Devansh Singh  
**Programme:** B.Tech Software Product Engineering  
**Institution:** Alliance University × Kalvium  
**Project Mentor:** Mr. Vaibhav Giri

## 📄 License

This project was developed for educational and academic purposes. Add a license such as the MIT License if you intend to distribute it for reuse.
