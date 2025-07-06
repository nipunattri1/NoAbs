// Multiplies R0 and R1 and stores the result in R2.
// (R0, R1, R2 refer to RAM[0], RAM[1], and RAM[2], respectively.)
// The algorithm is based on repetitive addition.



@R0
D=M

@count
M=D
// set count = R0

@R1
D=M
// Put R1 in Data resistor

// make sure R2 is 0
@R2
M=0

(LOOP)
    @count
    D = M
    @END
    D;JEQ

    @R1
    D = M

    @R2
    M=M+D

    @count
    M=M-1

    @LOOP
    0;JMP


(END)
    @END
    0;JMP
