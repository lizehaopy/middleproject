# ree.py
import re
s = '123asasd610528199002143611'
# r = re.subn(r'1',"%%",s,3)
# print(type(r))

pattern = r'\d+'
s = "2018年中国经济增长6.6%,与2017年基本持平,2019面临很多困难"
# r = re.finditer(pattern,s)
# #match对象
# print(r)
# print(next(r).group())
# print(next(r))
# print(next(r))
# print(next(r))

# obj = re.split(r'#','hello#1973')
# print(obj)

# obj = re.match(r'\w+','hello world')
# print(obj.group())
obj = re.search(r'\d+','123hell123oworldhello')
print(obj.group())