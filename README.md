
Github link:
# Relational Database Using Basic Operators from Relational Algebra in C++

## Project Overview
This project implements a console-based application that simulates a relational database system using object-oriented programming principles in C++. The application supports various relational algebra operations, showcasing the capabilities and functionalities of a relational database.

## Technologies Used
- **Programming Language:** C++
- **Object-Oriented Programming (OOP) Principles:** Encapsulation, Type Safety, Operator Overloading

## Key Functionalities
1. **Attribute Types:**
   - Implemented common attribute types such as integer, float, and string.
   - Utilized operator overloading with `dynamic_cast` for basic operations.

2. **Relational Algebra Operations:**
   - **Union:** Combines two relations.
   - **Difference:** Finds the difference between two relations.
   - **Cartesian Product:** Produces a set that is the Cartesian product of two sets.
   - **Projection:** Extracts specific columns from a relation.
   - **Selection:** Selects rows that satisfy a given predicate.
   - **Natural Join:** Joins two relations based on common attributes.

## Project Structure
- **Source Files:**
  - `rdb-attr.cpp`: Implementation of attribute types and their operations.
  - `rdb-basics.cpp`: Basic functionalities and helper functions.
  - `rdb-join.cpp`: Implementation of join operations.
  - `rdb-main.cpp`: Main driver code for the application.

- **Header File:**
  - `rdb.h`: Contains declarations for classes and functions used in the project.

- **Documentation:**
  - `assignment-3.pdf`: Detailed project assignment and requirements.

## How to Run
1. **Compile the Source Code:**
   Use a C++ compiler (like `g++`) to compile the source files. For example:
   ```bash
   g++ -o rdb rdb-main.cpp rdb-attr.cpp rdb-basics.cpp rdb-join.cpp
   ```

2. **Run the Application:**
   Execute the compiled binary:
   ```bash
   ./rdb
   ```

## Acknowledgments
This project was developed as part of the Relational Database I course at the Indian Institute of Technology Kharagpur, under the guidance of Prof. Abir Das and Prof. Sourangshu Bhattacharya.

---

For any further information or queries, please contact Hunny Chandra at hunnychandrahc12345@gmail.com    
