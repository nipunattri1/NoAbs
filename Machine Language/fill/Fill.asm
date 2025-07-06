// Runs an infinite loop that listens to the keyboard input. 
// Whesn a key i pressed (any key), the program blackens the screen,
// i.e. writes "black" in every pixel. When no key is pressed, 
// the screen should be cleared.
// check if to fill or  clear

(INIT)
    @count
    M = 0
    // Reinitialize the counter

    @KBD
    D = M


    // Go to CLR if KBD:D  = 0 else FILL
    @CLR
    D;JEQ
    @FILL
    0;JMP

(FILL)
    // compare counter with 8191 (max relative index of registers starting from 0)
    @count
    D = M
    
    @8191
    D = D - A


    // go to INIT is whole screen is FILLED
    @INIT
    D; JGT
     
    // set Screen base variable
    @SCREEN
    D = A

    // go to absolute index of register & increment the counter
    @count
    D = D + M
    M = M + 1

    
    A = D
    D = 0
    M = !D
    @FILL
    0;JMP



(CLR)
    // compare counter
    @count
    D = M
    @8191
    D = D - A


    @INIT
    D; JGT

    // set base index
     
    @SCREEN
    D = A

    // inc counter and set D = absolute index
    @count
    D = D + M
    M = M + 1

    A = D
    M = 0
    @CLR
    0;JMP






    
