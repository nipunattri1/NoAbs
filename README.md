# Assembler

A simple two-pass assembler for the Nand2Tetris Hack computer.  
This tool translates Hack assembly (`.asm`) files into binary machine code (`.hack`), including support for labels, variables, and all standard C‑instructions.

## Features

- Full support for the Hack instruction set:
  - A‑instructions: `@value` (literal or symbol)
  - C‑instructions: `dest=comp;jump`
- Two-pass (double parsing) symbol resolution:
  - Pass 1: Collects label definitions and ROM addresses
  - Pass 2: Resolves symbols (labels + variables) and emits binary code
- Built‑in predefined symbols (`R0`–`R15`, `SCREEN`, `KBD`)
- Automatic variable allocation starting at RAM address 16
- Ignores comments (`// ...`) and whitespace
- Outputs 16‑bit binary `.hack` files ready to run on the Nand2Tetris CPU emulator

## How double parsing works

The assembler uses a classic two‑pass algorithm:

1. **First pass (symbol table construction)**
   - Reads the assembly file line by line.
   - Strips comments and whitespace.
   - For each label declaration `(LABEL)`:
     - Adds `LABEL` to the symbol table with the current ROM address.
   - For each actual instruction (A or C):
     - Increments the ROM address counter.

2. **Second pass (code generation)**
   - Re-reads the assembly file.
   - For A‑instructions:
     - If the symbol is a number, use it directly.
     - If the symbol is not in the table, allocate a new RAM address (starting at 16).
     - Emit a 16‑bit A‑instruction: `0vvvvvvvvvvvvvvv`.
   - For C‑instructions:
     - Parse `dest`, `comp`, and `jump`.
     - Map each field to its corresponding bit pattern.
     - Emit a 16‑bit C‑instruction: `111accccccdddjjj`.

This double parsing keeps the implementation simple while correctly handling forward references and labels defined later in the file.

## Installation

Clone the repository:
```bash
git clone https://github.com/nipunattri1/Assembler
```
Build
```bash
cd src
g++ *.cpp -o assembler
```
Run
```bash
./assembler in.asm
```
