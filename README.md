# Educational Compiler for Simple Imperative Language

A complete educational compiler that translates a simple imperative programming language to x86 assembly code.

## Overview

This compiler implements a simple imperative programming language with static typing, arithmetic expressions, conditionals, loops, and nested scopes. It compiles source code to x86 assembly language.

## Language Features

- **Static typing** (INT, FLOAT)
- **Arithmetic expressions** with type conversion
- **Conditionals** (IF-THEN-ELSE)
- **Loops** (LOOP-UNTIL)
- **Nested scopes** with GLOBAL variables
- **Type conversion** (TOFLOAT)
- **String output** (PRINT)

## Prerequisites

- **Qt 6.6.0** or later
- **C++17 compiler** (clang++ from Xcode recommended)
- **GNU Bison** parser generator
- **macOS** (tested on macOS 26.0 SDK)

## Building the Compiler

### Method 1: Using Make
```bash
# Clean previous build
make clean

# Build the compiler
make
```

### Method 2: Using qmake
```bash
# Generate Makefile
qmake CompiladorQT.pro

# Build the compiler
make
```

### Regenerating Parser (if needed)
If you modify the grammar file:
```bash
bison -d -y GRAMATICA.y
```

## Running the Compiler

### Basic Usage
```bash
./CompiladorQT <source_file.txt>
```

### Examples
```bash
# Run basic test
./CompiladorQT "Codigos de prueba/prueba1.txt"

# Run loop test
./CompiladorQT "Codigos de prueba/pruebaLoop.txt"

# Run scope test
./CompiladorQT "Codigos de prueba/pruebaGlobal.txt"
```

## Language Syntax

### Data Types

**INT** - Integers with `_i` suffix:
```
INT a, b;
a = 5_i;
b = -10_i;
```

**FLOAT** - Floating-point numbers:
```
FLOAT x, y;
x = 3.0;
y = -10.5;
```

### Comments
```
// Single-line comment //
INT a;
a = 5_i;  // Comments can be inline //
```

### Variable Declaration
```
INT a;              // Single variable //
INT b, c, d;        // Multiple variables //
FLOAT x, y;         // Float variables //
```

### Assignment
```
INT a, b;
FLOAT x;
a = 5_i;
x = 3.0;
b = a + 10_i;
```

### Arithmetic Operators
```
INT a, b, c;
FLOAT x, y;
a = b + c;          // Addition //
a = b - c;          // Subtraction //
a = b * c;          // Multiplication //
a = b / c;          // Division //
```

### Comparison Operators
```
INT a, b;
IF (a < b) THEN      // Less than //
    PRINT('a is less than b');
IF (a > b) THEN      // Greater than //
    PRINT('a is greater than b');
IF (a <= b) THEN     // Less than or equal //
    PRINT('a is less than or equal to b');
IF (a >= b) THEN     // Greater than or equal //
    PRINT('a is greater than or equal to b');
IF (a == b) THEN     // Equal //
    PRINT('a equals b');
IF (a <> b) THEN     // Not equal //
    PRINT('a is not equal to b');
```

### Type Conversion
```
INT a;
FLOAT x;
a = 5_i;
x = TOFLOAT(a);     // Convert int to float //
PRINT('Conversion done');
```

### IF-THEN Statement
```
INT a;
a = 10_i;
IF (a > 5_i) THEN
    PRINT('Greater than 5');
```

### IF-THEN-ELSE Statement
```
FLOAT x;
x = 15.0;
IF (x >= 10.0) THEN
    PRINT('At least 10');
ELSE
    PRINT('Less than 10');
```

### BEGIN-END Blocks
```
INT a;
a = 5_i;
IF (a > 0_i) THEN
BEGIN
    a = a - 1_i;
    PRINT('Decremented');
END;
```

### LOOP-UNTIL (Post-test Loop)
```
INT a;
a = 0_i;
LOOP BEGIN
    a = a + 1_i;
    PRINT('Counting');
END; UNTIL (a >= 5_i);
```

### Nested Scopes
```
INT a;
a = 10_i;
{
    INT b;          // Local to this scope //
    b = 20_i;
    PRINT('Local b');
}
PRINT('Outer a');
```

### GLOBAL Variables
```
{
    INT a; // a is local to this scope only //
    GLOBAL a; // now a is a global variable //      
    a = 20_i;
}
a = 1_i; // now variable a can be accesed here // 
```

### PRINT Statement
```
PRINT('Hello World');
PRINT('Result is correct');
PRINT('Program finished');
```

## Complete Example

```
// Variable declarations //
INT a, b, c;
FLOAT x, y;

// Assignments //
a = 3_i;
b = 4_i;
x = 3.0;

// Arithmetic //
c = a + b;

// Type conversion and comparison //
IF (TOFLOAT(a) == x) THEN
    PRINT('Equal after conversion');
ELSE
    PRINT('Not equal');

// Loop //
a = 0_i;
LOOP BEGIN
    a = a + 1_i;
    PRINT('Iteration');
END; UNTIL (a >= 5_i);

// Nested scope //
{
    INT temp;
    temp = c * 2_i;
    c = temp;
    {
        GLOBAL temp;
        temp = 4_i;
    }
}

temp = 5_i;

PRINT('Done');
```

## Testing the Compiler

### Test Files

Located in `Codigos de prueba/`:
- `prueba1.txt` - Comprehensive test
- `pruebaLoop.txt` - Loop constructs
- `pruebaGlobal.txt` - Scope and GLOBAL variables
- `comparaciones.txt` - Comparison operators
- `divCero_*.txt` - Division by zero detection
- `overflowProd_*.txt` - Overflow detection

### Running Tests

```bash
# Basic test
./CompiladorQT "Codigos de prueba/prueba1.txt"

# Loop test
./CompiladorQT "Codigos de prueba/pruebaLoop.txt"

# Scope test
./CompiladorQT "Codigos de prueba/pruebaGlobal.txt"
```

### Output

**Console Output:**
- Errors (if any)
- Warnings
- Symbol table
- Intermediate code (tercets)
- Compilation status

**Generated File:**
- `assembler.asm` (in same directory as source file)

## Common Errors

### Integer without _i suffix
```
❌ INT a; a = 5;           // Wrong //
✓  INT a; a = 5_i;         // Correct //
```

### Type mismatch
```
❌ INT a; a = 3.0;  // Wrong - float assigned to int //
✓  INT a; a = 3_i;  // Correct //
```

### Missing semicolon
```
❌ INT a; a = 5_i          // Wrong //
✓  INT a; a = 5_i;         // Correct //
```

### Comparing different types
```
❌ INT a; FLOAT x; IF (a == x) THEN  // Wrong - different types //
✓  INT a; FLOAT x; IF (TOFLOAT(a) == x) THEN  // Correct - same types //
```

## Reserved Words

```
IF        THEN      ELSE      ENDIF
LOOP      UNTIL     BEGIN     END
INT       FLOAT     GLOBAL    PRINT
TOFLOAT
```

## Compiler Architecture

### Pipeline
```
Source Code (.txt)
    ↓
Lexical Analyzer (AnalizadorLexico)
    ↓
Parser (YACC - GRAMATICA.y)
    ↓
Code Generator (GeneradorDeCodigo)
    ↓
x86 Assembly (.asm)
```

### Components

1. **Lexical Analyzer** - Tokenizes source code
2. **Symbol Table** - Tracks variables and their attributes
3. **Parser** - YACC-based grammar with semantic actions
4. **Code Generator** - Creates intermediate code (tercets) and assembly

### Intermediate Representation

The compiler uses **tercets** (three-address code):
- Operations: +, -, *, /, =, BF (branch false), BI (branch), Label, PRINT, TOFLOAT
- Each tercet has: operation, operand1, operand2, auxiliary variable

## Limitations

- No arrays or complex data structures
- No functions (single main program)
- No input statements (only PRINT for output)
- No string variables (only literals)
- Two data types only (INT, FLOAT)
- No boolean type

## Quick Reference

| Feature | Syntax | Example |
|---------|--------|---------|
| Integer constant | `number_i` | `5_i`, `-10_i` |
| Float constant | `number.number` | `3.0`, `-10.5` |
| Declaration | `type var;` | `INT a;` |
| Assignment | `var = expr;` | `a = 5_i;` |
| Condition | `IF (cond) THEN` | `IF (a > 5_i) THEN` |
| Loop | `LOOP ... UNTIL (cond);` | `LOOP BEGIN ... END; UNTIL (a >= 5_i);` |
| Print | `PRINT('text');` | `PRINT('Hello');` |
| Convert | `TOFLOAT(expr)` | `TOFLOAT(5_i)` |
| Scope | `{ ... }` | `{ INT a; ... }` |
| Global | `GLOBAL var;` | `GLOBAL z;` |
| Comment | `// text //` | `// This is a comment //` |

## Troubleshooting

### Compilation Issues

If you encounter compilation errors:

1. **Qt version compatibility**: Ensure you have Qt 6.6.0 or later
2. **C++17 support**: Use a modern compiler that supports C++17
3. **Parser regeneration**: Run `bison -d -y GRAMATICA.y` if you modified the grammar
4. **Clean build**: Try `make clean && make` to rebuild from scratch

### Runtime Issues

- **File not found**: Ensure the source file path is correct
- **Permission denied**: Make sure the compiler executable has execute permissions
- **Assembly generation**: Check that the output directory is writable

## License

This is an educational project created for academic purposes.