#
#def decode(encrypt,k):
#import string
t=int(input())

while(t):

    k=int(input())
    inp=input()
    encrypt=inp.replace(" ","")
    #print(encrypt)
    result=""
    for i in range(len(encrypt)):
        char = encrypt[i]

        # Encrypt uppercase characters
        if (char.isupper()):
            result += chr((ord(char) - k-65) % 26 + 65)
    encrypt=result
    #print(encrypt)
    encrypt=encrypt.replace("QQ"," ")
    print(encrypt)
    t-=1
#return encrypt
