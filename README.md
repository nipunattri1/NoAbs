# From-NAND Computer System

This project is a complete implementation of a general-purpose computer system built from the ground up — starting with a single NAND gate and ending with a working CPU capable of running high-level programs.

Inspired by educational systems design, the goal is to demystify how computers work by constructing each hardware and software layer manually.

---

## 🧠 Overview

This repository includes the complete build of a simple 16-bit computer, broken down into logical modules:

- Basic logic gates
- Arithmetic Logic Unit (ALU)
- Sequential memory and registers
- CPU architecture
- Assembly language and assembler
- Virtual machine translator
- High-level programming language (compiler and OS, optional)

Each component is tested and validated with simulation tools and test scripts.

---

## 📁 Directory Structure

```
NoAbs/
├── 01-LogicGates/     # Basic gates (And, Or, Not, etc.)
├── 02-ALU/            # ALU components
├── 03-memory/         # Flip-flops, RAM, program counter
├── 04-cpu/            # CPU implementation
├── 05-computer/       # Integrated computer
├── 06-assembler/      # Converts assembly to machine code
├── 07-vm-translator/  # Stack-based virtual machine translator
├── 08-compiler/       # Compiler from high-level language (optional)
└── README.md          # Project documentation

```

---

## 🛠 How to Use

1. **Simulators**: Use the provided tools to simulate and test hardware (e.g., HardwareSimulator, CPUEmulator).
2. **Testing**: Each project contains `.hdl` files and `.tst` test scripts for verification.
3. **Assembler**: Run `.asm` files through an assembler to generate machine code.
4. **Run Programs**: Use the CPU emulator to execute `.hack` binary programs.

---

## 🔧 Technologies & Concepts

- Hardware Description Language (HDL)
- Digital logic design
- ALUs and CPU design
- Assembly and machine language
- Stack-based virtual machines
- Compiler and OS basics (optional)

---

## 🎯 Learning Objectives

- Gain low-level insight into computer architecture
- Understand the abstraction layers from logic gates to operating systems
- Reinforce digital logic and systems thinking through hands-on implementation

---

## 📚 References

- *The Elements of Computing Systems* by Nisan & Schocken (MIT Press)
- Educational tools and simulators provided for the course

---
