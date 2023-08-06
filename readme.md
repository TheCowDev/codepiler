
# ⚙️ Codepiler ⚙️ - A simple X86_64 compiler for the CODE programming language in C ⚙️

Codepiler is a simple compiler that generates x86_64 instructions for the CODE syntax.  It serves as a demonstration of how to build a compiler from scratch without relying on external dependencies.


## Design principle ✏️📄

The aim of this project is to create a performance-driven yet uncomplicated compiler. Here are some steps taken to achieve this:
- Only one reprensetation (IR) of the code throught the entire compiling process (no AST and and no tokens)

- Adopt straightforward parsing rules for the CODE syntax, using a simple top-down recursive descent parser.

## The CODE programming language  💻
CODE is a minimalistic low-level programming language with similarities to C, developed specifically for this implementation.

Here's a glimpse of the CODE syntax:
```Python
fn my_function(a : i32) -> i32:
    return a + 10
```


## ❗Missing feature ❗
- Type resolution
- Local variable
- Any loop / conditions (if / while / for)
- Condition operators
- Float operation
- Robust type check and error mecanism
- Output into ELF format (can only JIT for now)
- Register allocation
- Arguments / Calling convention
- JIT only works on Windows