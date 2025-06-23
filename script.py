letters = ['a', 'b','c','d ','e','f','g','h' ]
for l in range(len(letters)):
    letter = letters[l]
    str = f'''\tAnd(a={letter}Cond, b={letter}[0], out=temp{letter}[0]); 
        And(a={letter}Cond, b={letter}[1], out=temp{letter}[1]); 
        And(a={letter}Cond, b={letter}[2], out=temp{letter}[2]); 
        And(a={letter}Cond, b={letter}[3], out=temp{letter}[3]); 
        And(a={letter}Cond, b={letter}[4], out=temp{letter}[4]); 
        And(a={letter}Cond, b={letter}[5], out=temp{letter}[5]); 
        And(a={letter}Cond, b={letter}[6], out=temp{letter}[6]); 
        And(a={letter}Cond, b={letter}[7], out=temp{letter}[7]); 
        And(a={letter}Cond, b={letter}[8], out=temp{letter}[8]); 
        And(a={letter}Cond, b={letter}[9], out=temp{letter}[9]); 
        And(a={letter}Cond, b={letter}[10], out=temp{letter}[10]); 
        And(a={letter}Cond, b={letter}[11], out=temp{letter}[11]); 
        And(a={letter}Cond, b={letter}[12], out=temp{letter}[12]); 
        And(a={letter}Cond, b={letter}[13], out=temp{letter}[13]); 
        And(a={letter}Cond, b={letter}[14], out=temp{letter}[14]); 
        And(a={letter}Cond, b={letter}[15], out=temp{letter}[15]); \n'''
    print(str)
