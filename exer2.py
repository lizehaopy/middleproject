# exer2.py
import re
import sys

f = open('../1.txt','r')
data = f.read()
d = input("请输入端口号:")
pattern = r'%s.*?(\d+\.\d+\.\d+\.\d/?\d+|\w+\.\w+\.\w+|Unknown)'%d
regex = re.compile(pattern,flags=re.S)
neirong = regex.findall(data)
print(neirong)