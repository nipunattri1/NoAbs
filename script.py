letters = ['a', 'b','c','d','e','f','g','h' ]
for l in letters:

    
    str = f'''
    And16(a={l}, b=true, out={l}temp1);
    And16(a={l}, b=false, out={l}temp2);
    Mux16(b={l}temp1, a={l}temp2, sel={l}Cond, out=temp{l});\n'''
    print(str)
