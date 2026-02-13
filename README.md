# Tree of Meanings 🌳
A C++ engine for hierarchical idea visualization. 
*Current status: Building the core data structures based on Cormen's Algorithms.*

## The Vision
The goal of this project is to create an interactive tool that transforms raw text and data into organic "meaning trees." 
**Planned features:**
- Graphical rendering of trees (using Raylib).
- AI-assisted structure generation (automatic brainstorming).
- Marketplace for custom tree animations and styles.

  ### Lab 1: The Foundation (Elementary Data Structures)
- Defined the core `Node` class for a general tree structure. Implemented dynamic child management using `std::vector<Node*>`.
- Studied **Chapter 10** in Cormen's book.
- Learned how to represent rooted trees with an arbitrary number of children and how to use constructor initialization lists.

### Lab 2: The Magic of Recursion (DFS Traversal)
- Developed a recursive algorithm to visualize the tree hierarchy in the console.
- Applied principles from **Chapter 12.1 (Tree Walk)**. Implemented Depth-First Search (DFS) logic.
- Mastered recursion depth (the `level` parameter) to create visual indentation and understood recursive base cases.
