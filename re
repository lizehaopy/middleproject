re
正则表达式

动机: 
1.文本处理已经成为计算机常见的工作之一
2.对文本内容的搜索，定位，提取是逻辑比较复杂的工作
3.为了　快速　方便的解决上述问题　产生了正则表达式技术

定义：　即文本的高级匹配模式，提供搜索替换等功能
    　　由一系列字符和特殊符号构成的字符串

目标:1.熟练掌握正则表达式符号
    2.知道什么是正则表达式,如何应用
    3.能够读懂正则表达式,编写简单的正则匹配
    4.会使用re模块操作正则表达式

正则表达式特点:
1.方便文本处理
2.支持语言众多
3.使用灵活，变化多样。

 
findall(pattern, string, flags=0)
    Return a list of all non-overlapping matches in the string.
    
    If one or more capturing groups are present in the pattern, return
    a list of groups; this will be a list of tuples if the pattern
    has more than one group.
    
    Empty matches are included in the result.
    获取所有正则表达式匹配的内容

元字符的使用

1.普通字符 a b c
匹配规则:　每个字符匹配对应的字符

2.或
|　匹配｜两侧任意一个正则表达式规则

3.匹配单个字符
. 匹配除\n外任意一个字符

4.匹配字符串开始位置
"^" Matches the start of the string.
# '^a' 'absdadsasfs'  a(The first of str)

5.匹配字符串的结尾
$" Matches the end of the string or just before the newline at
the end of the string.
# 'a$' 'asdasdvsada' a(The end one)

6.匹配重复
 "*"  Matches 0 or more (greedy) repetitions of the preceding RE.
Greedy means that it will match as many repetitions as possible
# 匹配0次或者多次
'fo*' 'foooooasdasd' fooooo
匹配到f 为　o出现零次 fo表示出现一次

7.匹配重复
"+"  Matches 1 or more (greedy) repetitions of the preceding RE.
'fo+' 'fooooof' fooooo

8.匹配重复
"?"  Matches 0 or 1 (greedy) of the preceding RE.
匹配前面的字符一次或者零次
# 'as?' 'assssasa' as as a

9.匹配重复
{n} Matches n pice repetitions of the preceding RE.
匹配前面字符出现的指定次数
#'a{2}' 'assaass' aa

10.匹配重复
{m,n} Matches from m to n repetitions of the preceding RE.
匹配前面出现的字符m-n次
'as{2,5}','assssasassssa' assss assss

11.匹配字符集
[] Indicates a set of characters.
匹配字符集中任意一个字符
'f[asd]' 'fabfbbfeefrrfdd'  fa fd
# [a-z] [0-9] [abc123] [A-Z]

12.匹配字符集
[^...] 匹配除了字符集中的任意一个字符
同11
[^, ]+  'Hello im fucking,1997s'
'Hello im fucking 1997s'

13.匹配任意数字\非数字字符
 \d Matches any decimal digit; equivalent to the set [0-9] in
    bytes patterns or string patterns with the ASCII flag.
\D  Matches any non-digit character; equivalent to [^\d].
'1\d{10}' 'tel:17352628316' 17352628316

14.匹配任意普通字符\非普通字符
\w 匹配任意普通字符: 数字,字母,下划线 普通utf-8字符 [_0-9a-zA-Z]
\W 匹配任意非普通字符

15.匹配任意空字符\非空字符
\s 空字符
\S 非空字符

16.匹配字符串开头结尾位置
\A == ^
\Z == $
完全匹配 '\A.*\Z' 

17.匹配单词边界　非单词边界
\b  Matches the empty string, but only at the start or end of a word.
边界位置：数字,字母,下划线 普通utf-8字符和其他字符的交界位置为单词边界
\B  Matches the empty string, but not at the start or end of a word

正则表达式中如果表达特殊符号本身，则需要转义字符
. ? + * ^ $ [] () | \


贪婪和非贪婪

贪婪模式: 正则表达式中的重复匹配默认总是尽可能多的向后
匹配更多的内容
涉及元字符: * + ? {m,n}

非贪婪（懒惰）模式:尽可能少的重复匹配内容
'ab*?'
'ab+?'
'ab{3,5}?'
'ab??'


正则表达式分组
使用()可以为正则表达式内部建立若干分组
子组为正则表达式的一部分.

子组特点:
1.一个正则表达式内部可以有多个分组
2.分组后正则表达式仍然一个整体去匹配目标字符串
不会使用分组单独匹配
3.分组一般由外到内，由左到右计数，不会重叠

子组的作用：
1.将分组作为一个整体，改变元字符的操作对象
2.可以通过函数单独提取出子组的对应匹配内容
group(1)
3.可以通过命名注释子组含义,让结构分明.
 * 子组分为捕获组和非捕获组
 * 捕获组就是定义了名称的子组 (?P<name>pattern)

 正则表达式设计原则
 1.正确
 2.排他性(尽可能不去匹配到其他内容)
 3.全面性,尽可能对目标字符串各种情况考虑全面，不遗漏


re模块使用

regex = compile(pattern, flags=0)
功能:生成正则表达式对象
参数:pattern:正则表达式
    flags:功能标志位，丰富正则表达式的匹配功能
返回值:　返回正则对象

1.
re.findall(pattern,string,flags)
从目标字符串匹配所有正则内容
返回值：匹配到的内容列表,如果正则表达式有子组
    　　则只返回子组内容。

regex.findall(pattern,pos,endpos)
目标字符串　　对目标字符串截取的起始位置（默认开头）
终止位置(默认结尾)
regex.findall(s,pox=0,endpos=18)

2.
re.split(pattern,string,flags)
使用正则表达式匹配内容切割字符串
返回值:　列表　切割后的内容
re.split(r'\s+','hello world what   fucking')

3.
使用字符串替换正则匹配内容
re.sub(pattern,replaceStr,string,max,flags)
pattern 正则
replaceStr 替换的字符串
string  目标字符串
max 最多替换几处，默认全部替换
s = re.sub(r'\s+','##','hello world nihao kitty')

subn():与sub相同,多返回一个替换个数

4.
re.finditer(pattern,string,flags)
查找正则表达式匹配内容
返回值:返回一个迭代对象
match对象
使用group()可以获得匹配到的内容

re.fullmatch(pattern,string,flags)
功能:完全匹配目标字符串 (把目标字符串全部匹配出来)
返回值:匹配到的内容，失败返回None

re.match()
功能:匹配目标字符串开始位置
同上.....


re.search()
功能:匹配目标字符串第一处匹配内容
同上



regex对象属性

pattern:获取对应的正则表达式
regex.groups #获取正则表达式中有几个子组
regex.groupindex:获取捕获组组名和组序号的字典
flags:获取标志位





match对象 属性和方法

属性变量
pos
endpos
re
string
lastgroup
lastindex

span() 返回匹配内容起始位置和终止位置的元祖
start() 
end()
group() 返回匹配到的内容
groupdict() 返回捕获组组名和内容的字典
groups()


flags丰富的匹配  regx使用时：flags = re.
I,匹配时忽略大小写
A,只匹配ASCII字符
S,作用域.使其可以匹配\n
M 作用域^$使其可以匹配每行的开头结尾
X 可以给正则表达式每行加#注释
同时使用多个flag

flags = re.I|re.X
