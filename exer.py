# exer.py
import re
s = r'Matches any decimal digit; equivalent to the set [0-9] inbytes patterns or string patterns with the ASCII flag.\D  Matches any non-digit character; equivalent to [^\d].'

# r = re.findall(r'[A-Z][a-z]+',s)
# print(r)
# s = "123132 525 5265 3.59 ppdas8sad5asa"
# r = re.findall(r'\d+\.\d+|\d+',s)
# print(r)
# regx = re.compile(r'\d+\.\d+|\d+')
# r = regx.findall(s)
# print(r)

# regx = re.compile(r'\s+')
# r = regx.split(s)
# print(r)

# regx = re.compile(r'\s+')
# r = regx.subn("**",s)
# print(r)

# regx = re.compile(r'\d+')
# r = regx.finditer(s)
# for x in r:
#     print(x.group())

regx = re.compile(r'\w+')
print(regx.pattern)
r = regx.match(s)
print(r)
