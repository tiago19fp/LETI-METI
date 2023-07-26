#Cifra de cesar

import sys

def preproc(str):
    l = []
    for c in str:
        if c.isalpha():
            l.append(c.upper())
    return "".join(l)

def charshift(i, c):
    cord = ord(c) - ord('A')
    cord = (cord + i) % 26
    r = chr(ord('A')+cord)
    return r

def ceaser(i, str):
    str = preproc(str)
    l = []
    for c in str:
        l.append(charshift(i,c))
    return "".join(l)


# Se for chamada como script...
if __name__ == "__main__":
    if len(sys.argv) != 4:
        print("usage: python cesar.py [enc|dec] [key] [text]")
    else:
        if sys.argv[1]=='enc':
            k = ord(sys.argv[2])-ord('A')
            print(ceaser(k,sys.argv[3]))
        if sys.argv[1]=='dec':
            k = ord(sys.argv[2])-ord('A')
            print(ceaser(-k,sys.argv[3]))