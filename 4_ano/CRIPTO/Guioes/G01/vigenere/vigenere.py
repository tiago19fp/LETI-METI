#Cifra de vigenere

import sys

def preproc(str):
    l = []
    for c in str:
        if c.isalpha():
            l.append(c.upper())
    return "".join(l)

def char2int(c):
    return (ord(c) - ord('A')) % 26

def int2char(i):
    return chr(ord('A')+(i%26))

def charshift(i, c):
    return int2char(char2int(c) + i)

def ceaser(i, str):
    str = preproc(str)
    l = []
    for c in str:
        l.append(charshift(i,c))
    return "".join(l)

def vigenere(k, str):
    str = preproc(str)
    l = []
    for i in range(len(str)):
        l.append(ceaser(char2int(k[i % len(k)]), str[i]))
    return "".join(l)

# Se for chamada como script...
if __name__ == "__main__":
    if len(sys.argv) != 4:
        print("usage: python vigenere.py [enc|dec] [key] [text]")
    else:
        if sys.argv[1]=='enc':
            print(vigenere(sys.argv[2],sys.argv[3]))
        if sys.argv[1]=='dec':
            invk = [ int2char(-char2int(c)) for c in sys.argv[2] ]
            print(vigenere(invk,sys.argv[3]))