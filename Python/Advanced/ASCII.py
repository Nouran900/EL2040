def get_ascii(chara):
    return ord(chara)

if __name__=="__main__":
    char=input("please enter the character: ")

    if(len(char)!=1):
       char=input("please enter only one character: ")
    
    if(len(char)==1):
        Ascii=get_ascii(char)    
        print(f"the Ascii of character {char} is {Ascii}")     