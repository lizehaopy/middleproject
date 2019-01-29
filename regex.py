# regex.py
import re

# pattern = r'(ab)cd(?P<VanDarkHomle>ef)'
# regex = re.compile(pattern)
# obj = regex.search('abcdefgh',pos=0,endpos=8)
# print(obj.span())

s = r'''hello world
 .....asdasddadasdasdadas'''
regex = re.compile(r'world$',flags=re.M)
r = regex.findall(s)
print(r)