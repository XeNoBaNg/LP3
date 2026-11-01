# Laboratory Practice III (LP-3)

A curated repository containing all Laboratory Practice III (LP-3) practical assignments for Computer Engineering, organized by subject: **Machine Learning (ML)**, **Design & Analysis of Algorithms (DAA)**, and **Blockchain Technology (BT)**.

---

## 📂 Repository Structure

```
LP3/
├── BT/                                   # Blockchain Technology Practicals (Solidity)
│   ├── BankAccount.sol                   # Bank Account Smart Contract (Deposit, Withdraw, Balance)
│   └── StudentData.sol                   # Student Data Management Smart Contract with Structures
├── DAA/                                  # Design & Analysis of Algorithms (C++)
│   ├── Fibo.cpp                          # Fibonacci Numbers (Recursive vs Non-Recursive)
│   ├── Huff.cpp                          # Huffman Encoding using Greedy Strategy
│   ├── Knap.cpp                          # Fractional Knapsack Problem (Greedy Strategy)
│   ├── nq.cpp                            # N-Queens Problem using Backtracking & Branch and Bound
│   └── qs.cpp                            # Randomized Quick Sort vs Deterministic Quick Sort
└── ML/                                   # Machine Learning Practicals (Jupyter Notebooks)
    ├── uber1.ipynb                       # 1. Uber Fare Prediction (Linear Regression & Random Forest)
    ├── email1.ipynb                      # 2. Email Spam Classification (KNN & Linear SVM)
    ├── churn1.ipynb                      # 3. Bank Customer Churn Prediction (Artificial Neural Network)
    ├── gradient1.ipynb                   # 4. Gradient Descent Optimization on y = (x + 3)^2
    └── k-means1.ipynb                    # 5. Customer Sales Segmentation using K-Means Clustering
```

---

## 🤖 1. Machine Learning (ML)

All ML notebooks have been consolidated into **single, runnable code blocks** for quick copy-pasting, fast evaluation, and testing in VS Code, JupyterLab, or Google Colab.

| Assignment | Notebook | Key Concepts & Models | Highlights |
| :--- | :--- | :--- | :--- |
| **Assignment 1** | `ML/uber1.ipynb` | Linear Regression, Random Forest Regressor | Euclidean distance engineering, IQR outlier filtering, R² & RMSE metrics, comparative bar charts. |
| **Assignment 2** | `ML/email1.ipynb` | K-Nearest Neighbors (KNN), Linear SVM | Text token feature classification, confusion matrices, classification reports, accuracy bar comparison. |
| **Assignment 3** | `ML/churn1.ipynb` | Deep Learning (ANN with Keras/TensorFlow) | Categorical LabelEncoding, StandardScaler, Dense + Dropout(0.2) architecture, loss/accuracy curves. |
| **Assignment 4** | `ML/gradient1.ipynb`| Gradient Descent Algorithm | Minimizing $y = (x + 3)^2$ from $x=2.0$, tracking trajectory milestones, learning rate sensitivity curves. |
| **Assignment 5** | `ML/k-means1.ipynb` | K-Means Clustering (Unsupervised Learning) | Zero-loss data integrity pipeline, Elbow method + Silhouette analysis ($K=4$), 2D centroid visualization. |

---

## ⚡ 2. Design & Analysis of Algorithms (DAA)

| File | Problem Statement | Approach / Technique | Time Complexity | Space Complexity |
| :--- | :--- | :--- | :--- | :--- |
| `DAA/Fibo.cpp` | Fibonacci Sequence | Recursive vs Iterative | $\mathcal{O}(2^n)$ vs $\mathcal{O}(n)$ | $\mathcal{O}(n)$ vs $\mathcal{O}(1)$ |
| `DAA/Huff.cpp` | Huffman Coding | Greedy Strategy + Min-Heap | $\mathcal{O}(n \log n)$ | $\mathcal{O}(n)$ |
| `DAA/Knap.cpp` | Fractional Knapsack | Greedy Strategy (Value-to-Weight Ratio) | $\mathcal{O}(n \log n)$ | $\mathcal{O}(1)$ |
| `DAA/nq.cpp` | N-Queens Problem | Backtracking with 1st Queen Placed | $\mathcal{O}(n!)$ | $\mathcal{O}(n^2)$ |
| `DAA/qs.cpp` | Quick Sort Analysis | Deterministic vs Randomized Pivot | $\mathcal{O}(n \log n)$ avg, $\mathcal{O}(n^2)$ worst | $\mathcal{O}(\log n)$ |

---

## ⛓️ 3. Blockchain Technology (BT)

Solidity smart contracts written for deployment and testing in Remix Ethereum IDE or Hardhat/Truffle.

| File | Contract Name | Key Features |
| :--- | :--- | :--- |
| `BT/BankAccount.sol` | `BankAccount` | Ether deposits, balance tracking per account, withdrawal restrictions, fallback/receive functions. |
| `BT/StudentData.sol` | `StudentData` | `struct Student`, dynamic array storage, getter/setter functions, fallback handling. |

---

## 🚀 How to Use

### Machine Learning Notebooks
Open any `.ipynb` file in **VS Code**, **Jupyter Notebook**, or **Google Colab**. Each file contains a single complete cell:
1. Open the notebook.
2. Ensure required dependencies are installed (`pip install numpy pandas matplotlib seaborn scikit-learn tensorflow`).
3. Press `Shift + Enter` to run all preprocessing, model training, evaluation metrics, and visualizations.

### C++ DAA Programs
Compile and execute using `g++`:
```bash
g++ DAA/qs.cpp -o qs && ./qs
```

### Solidity BT Contracts
1. Copy the `.sol` file content into [Remix IDE](https://remix.ethereum.org/).
2. Select compiler version `^0.8.0` and compile.
3. Deploy to the Remix VM (Cancun / London) or Injected Provider (MetaMask).
