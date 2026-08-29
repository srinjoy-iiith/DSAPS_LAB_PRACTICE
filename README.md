# DSAPS Lab — C++ Practice

**Course:** M26-CS1.304 — Data Structures and Algorithms for Problem Solving
**Institute:** IIIT Hyderabad

My C++ solutions to problems practiced through the DSAPS lab across the semester. Problems are sourced from CSES, AtCoder, LeetCode, and SPOJ, and organized as the course progresses.

---

## Repo structure

```
.
├── <topic-or-lab-1>/
├── <topic-or-lab-2>/
├── <topic-or-lab-3>/
└── README.md
```

Each folder holds the `.cpp` files for one lab or topic. New folders are added as the semester moves forward.

---

## Naming convention

```
<problem-name>.cpp
```

Examples:

```
coin-combinations-i.cpp
knapsack.cpp
edit-distance.cpp
```

Files are named after the problem itself; the source and link live in the file header.

---

## File header

Every solution starts with a short comment block linking back to the problem:

```cpp
// Problem : <name>
// Judge   : <judge> <id>
// Link    : <url>
// Idea    : <one-line approach>
```

---

## Build & run

Compiled with C++17:

```bash
g++ -std=c++17 -O2 -Wall file.cpp -o sol
./sol < input.txt
```

Quick one-liner while iterating:

```bash
g++ -std=c++17 -O2 file.cpp -o sol && ./sol
```

---

## Judges

- [CSES Problem Set](https://cses.fi/problemset/)
- [AtCoder](https://atcoder.jp/)
- [LeetCode](https://leetcode.com/)
- [SPOJ](https://www.spoj.com/)

---

## Author

**Srinjoy Majumdar (Joy)** — M.Tech CSE, IIIT Hyderabad

- GitHub: [srinjoy-iiith](https://github.com/srinjoy-iiith)
- LeetCode: [7NS3i7FOsq](https://leetcode.com/u/7NS3i7FOsq)
- LinkedIn: [srinjoy-majumdar](https://linkedin.com/in/srinjoy-majumdar-iiith18568a410)
