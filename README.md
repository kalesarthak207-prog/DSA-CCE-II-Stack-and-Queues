DSA CCE-II – Stacks and Queues

📌 Project Overview

This repository contains C++ programs developed for CCE-II of Data Structures and Algorithms (DSA). The project demonstrates the implementation and working of Stack and Queue data structures using both Arrays and Linked Lists.

The programs are menu-driven and demonstrate basic operations such as insertion, deletion, display, push, pop, enqueue and dequeue.

---

👨‍🎓 Student Details

Name: Sarthak Kale
Class: S.Y. B.Tech
Branch: Electronics and Computer Engineering
Subject: Data Structures and Algorithms
CCE: CCE-II
Programming Language: C++

---

🎯 Objectives

The main objectives of this project are:

- To understand the concept of Stack and Queue data structures.
- To implement Stack using an Array.
- To implement Queue using an Array.
- To implement Stack using a Linked List.
- To implement Queue using a Linked List.
- To understand the basic operations performed on Stack and Queue.
- To understand the difference between static and dynamic memory implementation.
- To develop programming and problem-solving skills using C++.

---

📚 Concepts Covered

1. Stack

A Stack is a linear data structure that follows the LIFO (Last In, First Out) principle.

Example:

Last element inserted
        ↓
      [30]  ← TOP
      [20]
      [10]

Stack Operations

- Push – Inserts an element into the stack.
- Pop – Removes the top element.
- Peek/Top – Displays the top element.
- Display – Displays all elements of the stack.

---

2. Queue

A Queue is a linear data structure that follows the FIFO (First In, First Out) principle.

Example:

FRONT                    REAR
  ↓                        ↓
[10] → [20] → [30] → [40]

Queue Operations

- Enqueue – Inserts an element at the rear.
- Dequeue – Removes an element from the front.
- Peek/Front – Displays the front element.
- Display – Displays all elements of the queue.

---

💻 Implementations

This repository contains the following implementations:

1. Stack Using Array

Implementation of Stack using a fixed-size array.

Operations:

- Push
- Pop
- Peek/Top
- Display

Principle: LIFO

---

2. Queue Using Array

Implementation of Queue using an array.

Operations:

- Enqueue
- Dequeue
- Front
- Display

Principle: FIFO

---

3. Stack Using Linked List

Implementation of Stack using dynamically allocated linked-list nodes.

Operations:

- Push
- Pop
- Peek/Top
- Display

Principle: LIFO

Advantage: Size can grow dynamically according to the available memory.

---

4. Queue Using Linked List

Implementation of Queue using linked-list nodes.

Operations:

- Enqueue
- Dequeue
- Front
- Display

Principle: FIFO

Advantage: Dynamic memory allocation and flexible size.

---

📂 Repository Structure

DSA-CCE-II-Stack-and-Queues/
│
├── Stack_Array.cpp
├── Queue_Array.cpp
├── Stack_LinkedList.cpp
├── Queue_LinkedList.cpp
│
└── README.md

«File names can be changed according to the actual names of the programs in the repository.»

---

⚙️ Requirements

To run these programs, you need:

- C++ compiler
- VS Code / Code::Blocks / Dev-C++ / any C++ IDE
- Basic knowledge of C++

A compiler such as G++ can be used to compile the programs.

---

▶️ How to Run

Step 1: Clone the Repository

git clone <repository-link>

Step 2: Open the Project

Open the downloaded folder in your preferred C++ IDE or VS Code.

Step 3: Compile the Program

Example:

g++ Stack_Array.cpp -o Stack_Array

Step 4: Run the Program

./Stack_Array

For Windows PowerShell:

.\Stack_Array.exe

Follow the menu displayed by the program and select the required operation.

---

🧪 Sample Menu

A typical menu-driven program provides options such as:

----- STACK MENU -----

1. Push
2. Pop
3. Peek
4. Display
5. Exit

Enter your choice:

For Queue:

----- QUEUE MENU -----

1. Enqueue
2. Dequeue
3. Front
4. Display
5. Exit

Enter your choice:


---

🌍 Real-Life Applications

Stack Applications

- Function calls
- Undo/Redo operations
- Browser back button
- Expression evaluation
- Parentheses matching
- Recursion

Queue Applications

- Printer scheduling
- CPU scheduling
- Customer service systems
- Network data handling
- Task scheduling
- Breadth First Search (BFS)

---

🧠 Learning Outcomes

After completing this project, the following concepts were understood:

- Working of Stack and Queue.
- LIFO and FIFO principles.
- Push, Pop, Enqueue and Dequeue operations.
- Array-based implementation.
- Linked-list-based implementation.
- Dynamic memory allocation.
- Overflow and Underflow conditions.
- Practical use of Stack and Queue in computer science.

---

⚠️ Important Conditions

Stack Overflow

Occurs when we try to insert an element into a full stack.

Stack Underflow

Occurs when we try to remove an element from an empty stack.

Queue Overflow

Occurs when there is no available space for inserting a new element in a fixed-size queue.

Queue Underflow

Occurs when we try to remove an element from an empty queue.

---

✅ Conclusion

This project successfully demonstrates the implementation of Stack and Queue using Arrays and Linked Lists in C++. It provides a practical understanding of LIFO and FIFO principles, basic data structure operations, memory allocation, and their real-world applications.

The implementation helped in developing a better understanding of linear data structures and their use in solving computational problems.

---

👨‍💻 Author

Sarthak Kale

S.Y. B.Tech
Electronics and Computer Engineering
Data Structures and Algorithms

---

⭐ Acknowledgement

This project was completed as part of the CCE-II activity for Data Structures and Algorithms. The implementation was developed for academic learning and practical understanding of Stack and Queue data structures.