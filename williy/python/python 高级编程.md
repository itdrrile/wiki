## python 高级编程

## 1 引用

* 变量也称为对象的引用，因为变量存储的就是对象的地址
* 变量位于堆内存
* 对象位于栈内存

### 2 时间

* datetime模块

  ```python
  import datetime
  datetime_local = datetime.datetime.now()  #获取datetime类型的本地时间
  datetime_utc = datetime.datetime.utcnow() #获取datetime类型的utc时间
  
  time_str = datetime.local.striftime("%Y-%m-%d, %H:%M:%S, %w") #datetime类型->时间字符串
  datetime_type = datetime.datetime.striptime("2016-11-15, 15:32:12, 2", "%Y-%m-%d, %H:%M:%S, %w") #时间字符串->datetime类型
  
  ts = datetime_local.timestamp()  #datetime->timestamp
  date_local = datetime.datetime.fromtimestamp(time.time()) #timestamp->datetime
  date_utc = datetime.datetime.utcfromtimestamp(time.time()) #timestamp->utc datetime
  ```

* time模块

  ```python
  import time
  
  time_stamp = time.time() #时间戳
  local_time = time.localtime(time_stamp)  #timestamp->struct time类型
  utc_time = time.gmtime(time_stamp) #timestamp->struct utc time
  
  time_stamp = time.mktime(local_time)  # struct time -> time stamp
  time_stamp = calendar.timegm(utc_time) #struct utc time -> time stamp
  
  
  ```

  



### 3 深拷贝和浅拷贝

* 概念
  * 浅拷贝：不拷贝子对象的内容，只拷贝子对象的引用
  * 深拷贝：会连对象的内存也拷贝一份，对子对象的修改不会影响原对象

### 4 异常处理

* 常见的异常

  ![preview](https://pic1.zhimg.com/v2-b02b9d18b72da98ab6d29082be251d0c_r.jpg)

* try...except...else...，else后的语句块当异常没有发生时才会执行

  ```python
  while True:
      try:
          i = int(input('接收一个除数'))
      except ZeroDivisionError: #只捕获某个特定的异常
      	print("zeroDivisionError")
      except (ValueError, KeyboardInterrupt, TypeError): #捕获多个异常
          print('ValueError or KeyboardInterrupt or TypeError')
      except: #可以捕获所有异常
          print('all other exceptions')
      else: #当语句块没有异常的时候执行
          print("the program end")
  ```

* try...except...finally...，finally下的语句块不管有没有发生异常都会执行

  ```python
  while True:
      try:
          i = int(input('接收一个除数'))
          print(2/i)
      except:
          print('caught all the exception')
      finally: #不管有没有发生异常都会执行
          print('excute the finally block whenever has exception')    
  ```

* try... except...else...finally...的使用顺序

  * else必须在except之后，finally之前
  * finally只能在最后
  * else和finally可有可无

* raise

  * raise 异常类型('异常描述')

### 5 lambda 匿名函数

* 定义 

  lambda [参数1,参数2]:表达式

  ``` python g = lambda x: x*x + 1
  g = lambda x: x*x + 1
  ```

* if else

  ```python
  func = lambda x, y: x if x > y else y
  ```

* lambda匿名函数的灵活应用

  * filter(function, sequence) 过滤筛选序列中的数据，返回可迭代对象
  * map(function, sequence) 将function调用映射到每个对象上，返回可迭代对象
  * reduce(function, sequence, initial) 累积函数

  ```python
  list1 = [1, 18, 9, 7, 17, 12, 6]
  f = filter(lambda x:x%2==0, list1)
  m = map(lambda x:x*2 + 10, list1)
  r = reduce(lambda x, y:x + y, list1)
  r = reduce(lambda x, y:x + y, list1, 1)
  ```


### 6 可变参数

* *args 序列可变参数

  * args加了*的参数名会存放所有命名的不带键的参数，将这些参数转化成一个元组，存储在args中

  * 例子

    ```python
    def variablefun(name, *args):
        print(args)
        
    tuple1 = ('女', 20)
    variablefun("lucy", tuple)
    variablefun("lucy", *tupe)
    variablefun("lucy", "女", 20)
    
    #打印的结果分别为：
    # (('女', 20),)
    # ('女', 20)
    # ('女', 20)
    ```

    

* **kwargs 键值对可变参数

  ```python
  def fun(name, **kwargs):
      print(kwargs)
      
  fun("lucy", **{"sex":'woman', 'age':20}) #可以传入dict，但必须带**
  fun("lucy", sex='woman', age=20)
  fun(**{'name':"lucy", 'sex':'woman', 'age':20}) #也可以把name参数放在dict里面一起传入
  
  #打印的结果分别为：
  # {"sex":'woman', 'age':20}
  # {"sex":'woman', 'age':20}
  # {"sex":'woman', 'age':20}
  ```

  

### 7作用域

* 作用域类型
  * L(Local) 局部作用域
  * E(Enclosing) 闭包函数外的函数中
  * G(Global) 全局作用域
  * B(Built-in) 内建作用域
* 全局变量和局部变量
  * 定义在函数内部的变量拥有一个局部作用域
  * 定义在函数外的变量拥有全局作用域

* global关键字

  * 当局部作用域想要修改全局作用域的变量时，就要用到global关键字

    ```python
    num = 123
    def fun1():
        global num #使用global关键字声明，使num全局变量值可在函数内修改
        print(num)
        num = 456 #修改全局变量的值
    ```

* nonlocal

  * 如果想要修改嵌套作用域中变量则需要nonlocal关键字

  ```python
  def out():
      num = 10
      def inner():
          nonlocal num
          num = 100 #修改out内部变量的值
      inner()
  ```

### 8 装饰器

* 装饰器的两种方式

  ```python
  #方式一
  import time
  
  def wrap(func):
      def wrapper(args):
          print(time.time())
          func(args)
          print(time.time())
      return wrapper
  
  @wrap  # wrap(test_fun)(args)
  def test_fun(args):
      print(args)
      
  #方式二
  def wp(sex):
      def wrap(func):
          def wrapper(args):
              if sex == "man":
                  print("you are a good man")
              elif sex == "woman":
                  print("you are a good woman")
              func(args)
          return wrapper
      return warp
  
  @wp(sex="woman") # wp(sex)(test_fn)(args)
  def test_fn(args):
      print(args)   
  ```


### 9 并行迭代

```python
names = ["zhangshan", 'lisi', 'wangwu']
ages = [18, 19, 20]
sexes = ("man", "man", "man")
for name, age, sex in zip(names, ages, sex):
    print("{}-{}-{}".format(name, age, sex))
```

### 10 推导式

* 列表推导式

  * 定义：通过推导式生成列表对象

  * 语法： {表达式 for item in 可迭代对象 if 条件判断}

  * 例子

    ```python
    list1 = [x for i in range(1, 5)]
    list2 = [(row, col) for row in range(1, 10) for col in range(2, 11)]
    ```

* 字典推导式

  * 语法：{key_expression: value_expression for 表达式 in 可迭代对象  if 条件判断}

  * 例子

    ```pytho
    my_text = 'I love rain so much'
    char_cout_dict = {ch:my_text.count(ch) for ch in my_text}
    
    dict1 = {key:val for key in range(5) for val in range(5) if key != 3 if val !=4}
    ```

* 集合推导式

  * 语法：{表达式 for item in 可迭代对象 if 条件判断}

    ```python
    clt = {x for x in range(1, 100) if x%9==0}
    ```

* 元组推导式

  * 语法：tuple((i for i range(3)))

  * 例子

    ```pytho
    tuple_generator = (i for i in range(4))  #是元组生成器，且只能运行一次
    tuple_data = tuple(tuple_generator)
    ```

    

