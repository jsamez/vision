#%%
from IPython.core.interactiveshell import InteractiveShell
InteractiveShell.ast_node_interactivity = "all"
#c/c++
#int/ short/ double/.....
#char/ string
#연속메모리 : array
#집합 : struct
#기능 : function
#모듈 : class

#python
#int : 정수, float : 실수, str : 문자열
#연속 메모리 : list ... container
#               [everything...]
#집합 : list
#기능 : function
#모듈 : class

#%%

aa = 123
print('aa = ' , aa, 'type = ' , type(aa))
aa=123.000
print('aa = ', aa, 'type = ', type(aa))
aa = 'aaaa'
print('aa = ', aa, 'type = ', type(aa))

# %%

#array
#list ... data container
aa = [1,2,3]
print('aa = ', aa, ' type = ', type(aa))
aa[0] = aa[0]+1
print('aa = ', aa, ' type = ', type(aa))
aa[1] = aa[1]+1
print('aa = ', aa, ' type = ', type(aa))
aa[2] = aa[2]+1
print('aa = ', aa, ' type = ', type(aa))

#tupel ... data container ... read only
aa = (1,2,3)
print('aa = ', aa, ' type = ', type(aa))
#aa[0] = aa[0]+1 #error

#dict ... dictionary ... data container ... read/write/searching
#aa = {'key': 'value'}
aa = {'ㄱ':'가족', 'ㅎ':'홍길동'}
print('aa = ', aa, ' type = ', type(aa))
aa = {'a':'apple', 'g':'google'}
print('aa = ', aa, ' type = ', type(aa))
aa['a'] = 'amazon'
print('aa = ', aa, ' type = ', type(aa))
aa = {0: '0000', 1: '0001', 2:'0010'}
print('aa = ', aa, ' type = ', type(aa))
aa[0] = '0x00'
print('aa = ', aa, ' type = ', type(aa))


# %%
aa = True
aa = False

#len()
#type()
#print()

#c++
#int * pArr = new int[10]
#array_size = sizeof(pArr)/sizeof(pArr[0])
#vector<int> vArr;
#vArr.push_back(10);
#vArr.push_back(20);
#vArr.push_back(30);
#   vArr_size = vArr.size()

aa= [1,2,3,4,5]
print('aa size = ', len(aa))
aa = [1,2,3]
print('aa size = ', len(aa))
aa = [1,2,3,4,5,6,7,8,9,10,11]
len(aa)

# %%
x=3
y= x*2
y
y=x**3
y

x = 9
y = x/2
y
y = x//2
y
# %%
hello = 'hello'
world = 'world'
hello
world
len(hello)
len(world)
hw = hello + ' ' + world
hw
fmt = '%s %s %d'%(hello, world, 777)
type(fmt)
fmt = f'{hello:10s} {world:10s} {7777:010d}'
type(fmt)
import numpy as np
print(np.pi)
fmt = f'{hello:10s} {world:10s} {123.123456:0.6f}'
print(fmt, '    type = ', type(fmt))

# %%
s = "hello"
print(s.capitalize())  # Capitalize a string; prints "Hello"
print(s.upper())       # Convert a string to uppercase; prints "HELLO"
print(s.rjust(7))      # Right-justify a string, padding with spaces; prints "  hello"
print(s.center(7))     # Center a string, padding with spaces; prints " hello "
print(s.replace('l', '(ell)'))  # Replace all instances of one substring with another;
                                # prints "he(ell)(ell)o"
print('  world '.strip())  # Strip leading and trailing whitespace; prints "world"
#['h','e','l','l','o']
print(s[0:1])#h
print(s[1:2+1])#el
print(s[2:3+2])#llo

for i in range(0,9+1,1):
    print('i = ', i)

# %%
nums = list(range(5))     # range is a built-in function that creates a list of integers
print(nums)               # Prints "[0, 1, 2, 3, 4]"
print(nums[2:4])          # Get a slice from index 2 to 4 (exclusive); prints "[2, 3]"
print(nums[2:])           # Get a slice from index 2 to the end; prints "[2, 3, 4]"
print(nums[:2])           # Get a slice from the start to index 2 (exclusive); prints "[0, 1]"
print(nums[:])            # Get a slice of the whole list; prints "[0, 1, 2, 3, 4]"
print(nums[:-1])          # Slice indices can be negative; prints "[0, 1, 2, 3]"
nums[2:4] = [8, 9]        # Assign a new sublist to a slice
print(nums)
# %%
'''
True and True = True
True and False = False
False and True = False
False and False = False

True or True = True
True or False = True
False or True = True
False or False = False
'''
cond = True
if cond and True:
    if cond:
        if cond or False: 
            print('True')
else:
    print('False')

# %%
for i in range(0,10,1):
    print('i = ',i)
datas = [1,2,3,4,5,6,7,8,9,10]
for i in range(0,len(datas),1):
    print(f'datas[{i}] = {datas[i]}')
#for i in range(0,10,1)
#for(const auto& data : datas)
for data in datas:
    print(data)
for i, data in enumerate(datas):
    print(f'datas[{i}] = {datas}')
# %%
#for + if -> gugudan
for step in range(1, 9+1, 1):
    for dan in range(2, 9+1, 1):
        print(f'{dan} * {step} = {dan*step}',end = '\t')
    print(' ')
print(' ')

for dan in range(2, 9+1, 1):
    for step in range(1, 9+1, 1):
        print(f'{dan} * {step} = {dan*step}')
    print(' ')

# %%
# for + if -> gugudan
awr = ''
for dan in range(1, 9+1, 1):
    for step in range(1, 9+1, 1):
        awr = awr + f'{dan}x{step}={dan*step:2d}  '
    awr = awr + '\n'

print(awr)
# %%
xs = [3, 1, 2]    # Create a list
print(xs, xs[2])  # Prints "[3, 1, 2] 2"
print(xs[-1])     # Negative indices count from the end of the list; prints "2"
xs[2] = 'foo'     # Lists can contain elements of different types
print(xs)         # Prints "[3, 1, 'foo']"
xs.append('bar')  # Add a new element to the end of the list
print(xs)         # Prints "[3, 1, 'foo', 'bar']"
x = xs.pop()      # Remove and return the last element of the list
print(x, xs)
# %%
nums = [0,1,2,3,4]
print('nums = ', nums , '   type = ', type(nums))
nums = list(range(5))
print('nums = ', nums , '   type = ', type(nums))
squares = [x ** 2 for x in nums]
print('Squares = ', squares , '   type = ', type(squares))
'''
std::vector<int> vSequares;
for(int i = 0; i<5; i++)
{
    int tmp = nums[i]*nums[i]
    int tmmp = std::pow(nums[i], 2.0)
    vSequares.push_back()

}
'''
# %%
animals = ['cat','dog','monkey',1,2,3,1.123,3.141592,['cat','dog','monkey']]
for animal in animals:
    print(animal)
for idx, animal in enumerate(animals):
    print(f'animals[{idx}] = {animals}')

# %%
Dans = list(range(2,10))
Steps = list(range(1,10))
dan_start = 2
dan_finish = 9
step_start = 1
step_finish = 9
ggd = [
    f'{Dan}x{Step} = {Dan*Step}'
    for Dan in range(dan_start, dan_finish+1)
    for Step in range(step_start, step_finish+1)
]

for i in range(0, dan_finish-1):
    print(ggd[(i*step_finish):(i+1)*step_finish])

# %%
def sum(a,b):
    return a+b
def sum_div(a,b):
    return (a+b,a/b)
def calc(a,b):
    return (a+b, a-b, a*b, a/b)

a= 10
b=20
c = sum(a,b)
c,d = sum_div(a,b)
print(f'{c} = {a}+{b}')
print(f'{d} = {a}/{b}')

c,d,e,f = calc(a,b)
print(f'{c} = {a}+{b}')
print(f'{d} = {a}-{b}')
print(f'{e} = {a}x{b}')
print(f'{f} = {a}/{b}')

def calc_list(a,b):
    return [a+b, a-b, a*b, a/b]

cc = calc_list(a,b)
print(f'{cc[0]} = {a}+{b}')
print(f'{cc[1]} = {a}-{b}')
print(f'{cc[2]} = {a}x{b}')
print(f'{cc[3]} = {a}/{b}')

# %%
def gugudan(dan_start, dan_finish, step_start, step_finish):
    ggd = [
     f'{Dan}x{Step} = {Dan*Step}'
      for Dan in range(dan_start, dan_finish+1)
     for Step in range(step_start, step_finish+1)
    ]
    for i in range(0, dan_finish-dan_start+1):
        print(ggd[(i*step_finish):(i+1)*step_finish])

gugudan(3,7,1,5)

# %%
