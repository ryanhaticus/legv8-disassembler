# LEGv8 Disassembler

Enclosed in this repository is a disassembler (binary to assembly) for 32-bit LEGv8 (a subset of ARM first described by David A. Patterson and John L. Hennessy) instructions written in C++.

## Coursework

This project was developed as part of COM S 321 (Computer Architecture) at Iowa State University, instructed by Dr. Jeremy Sheaffer.

## What's included?

The disassembler can handle the following instruction types:

- B
- CB
- D
- I
- IW
- R

Specifically, supporting the following instructions:

- ADD
- ADDI
- AND
- ANDI
- B
- B.cond (EQ, NE, HS, LO, MI, PL, VS, VC, HI, LS, GE, LT, GT, LE)
- BL
- BR
- CBNZ
- CBZ
- EOR
- EORI
- LDUR
- LSL
- LSR
- ORR
- ORRI
- STUR
- SUB
- SUBI
- SUBIS
- SUBS
- MUL

Along with these special instructions, implemented by some emulators:

- PRNT
- PRNL
- DUMP
- HALT

## Endianness

As most modern systems are little-endian, we assume that the input binary is little-endian.

## Usage

Per course guidelines, the project ships with a `build.sh` and `run.sh` - these do what you expect.

To build the project, simply run `./build.sh`. You must have `make` and `g++` installed ahead of time. You will see the executable `disasm` generated. You may execute this binary directly, or use the provided `run.sh` script.

Next, to disassemble a binary, run `./run.sh <path-to-binary>`. The disassembled output will be written to `<path-to-binary>.legv8asm`. For example, if you run `./run.sh test.bin`, the output will be written to `test.bin.legv8asm`.

## Considerations

When originally approaching this project, I had wanted to use a more object-oriented approach. However, I quickly realized it'd be rather burdensome to ensure I was shifting out values and storing them in class members correctly.

Instead, I opted to create classic C `struct`s to represent the various instruction types. Once I dynamically identify an instruction's opcode, I can then cast the `uint32_t` bitfield to the appropriate `struct` and access the fields directly without headache. For those interested in creating a disassembler, I highly recommend this approach.
