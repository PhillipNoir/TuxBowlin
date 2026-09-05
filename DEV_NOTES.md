# Development and Architecture Notes - TuxBowlin

This document is a personal log regarding design decisions, C++ quirks, and solutions to problems encountered during development.

---

## [2026-09-05] - Dynamic paths, pointers, and the Early Exit pattern

### 1. The silent danger of `std::getenv`
**The Concept:** In C++, requesting data from the operating system (such as the `HOME` variable on Linux) requires using `std::getenv("<variable>")`.
**The Trap:** This function returns a C-style pointer (`char*`). If the environment variable does not exist, it returns `nullptr`.
**The Fatal Error:** The compiler allows passing that `nullptr` directly to constructors like `std::filesystem::path` because the types match; however, at runtime, attempting to read that null memory causes a **Segmentation Fault** (Undefined Behavior / UB).

*Lesson learned:* NEVER feed the return value of `getenv` directly into standard library functions without first storing it in a variable and validating that it is not null.

### 2. The "Early Exit" Pattern (Guard Clause)
**The Concept:** Instead of nesting the code's "happy path" inside multiple `if` blocks, it is better to catch errors first and abort execution immediately using `return`.

**Before (Arrow Code - Hard to read):**
```cpp
if (puntero != nullptr) {
// Useful code lines here
} else {
// Error
}
```

**After (Flat, clean code):**

```cpp
if (puntero == nullptr) {
std::cout << "Fatal error\n"; 
return 1; // Abort. Goodbye 'else'.
}
// Useful code lines continue aligned to the left margin.
```

### 3. <filesystem> in C++17

The Concept: Constructing directory paths by concatenating strings (string1 + "/" + string2) is error-prone due to the slashes (/ or \).
The Solution: std::filesystem::path overloads the division operator (/). When used, the compiler automatically and safely handles the insertion of the correct slashes for the specific operating system.
**Usage example:**
std::filesystem::path path = std::filesystem::path(homeDir) / "Documents" / "GTAIV_Tests";


### 4. std::endl vs \n

The Concept: std::endl not only inserts a line break but also forces a buffer flush. In repetitive operations, this destroys I/O performance.
Rule: Use \n by default with std::cout, unless flushing the buffer at that specific moment is strictly necessary.