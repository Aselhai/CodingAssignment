# Password Encryption/Decryption Program
import sys

# init
password_out = ''
case_changer = ord('a') - ord('A')
encryption_key = (('a','m'), ('b','h'), ('c','t'), ('d','f'), ('e','g'),
  ('f','k'), ('g','b'), ('h','p'), ('i','j'), ('j','w'), ('k','e'),('l','r'),
  ('m','q'), ('n','s'), ('o','l'), ('p','n'), ('q','i'), ('r','u'), ('s','o'),
  ('t','x'), ('u','z'), ('v','y'), ('w','v'), ('x','d'), ('y','c'), ('z','a'),
  ('#','!'), ('@','('), ('%',')'), ('0','0'), ('1','1'), ('2','2'), ('3','3'),
  ('4','4'), ('5','5'), ('6','6'), ('7','7'), ('8','8'), ('9','9'))

encrypting = True
    
# get password
password_in = input('Enter password: ')

# perform encryption / decryption
if encrypting:
    from_index = 0
    to_index = 1
else:
    from_index = 1 
    to_index = 0

case_changer = ord('a') - ord('A')

eng_found = False
non_found = False
dig_found = False

for ch in password_in:
    letter_found = False
    for t in encryption_key:
        if ('0' <= ch and ch <= '9') and ch == t[from_index]:
            password_out = password_out + ch
            letter_found = True
            dig_found = True
        elif ('a' <= ch and ch <= 'z') and ch == t[from_index]:  
            password_out = password_out + t[to_index]
            letter_found = True
            eng_found = True
        elif ('A' <= ch and ch <= 'Z') and chr(ord(ch) + 32) == t[from_index]:
            password_out = password_out + chr(ord(t[to_index]) - case_changer)
            letter_found = True
            eng_found = True
        elif ('#' == ch or '@' == ch or '%' == ch) and ch == t[from_index]:
            password_out = password_out + t[to_index]
            letter_found = True
            non_found = True
        
    if not letter_found:
        print('Invalid password!')
        sys.exit()
##        password_out = password_out + ch

# output
if non_found == False or eng_found == False or dig_found == False:
    print('Invalid password!')
    sys.exit()
        
if encrypting:
    print('Your encrypted password is:', password_out)   
else:
    print('Your decrypted password is:', password_out)
