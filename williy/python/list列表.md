# list列表

### 1 新增列表的值

append在列表的末尾追加值

insert在列表的指定位置插入值

###  2 删除元素

* del 删除列表的某个索引的元素
  * del ls[0:2]      
  * del ls[0]
* pop通过列表索引号来删除list元素，不指定索引号时删除最后一个元素
  * ls.pop()
  * ls.pop(1)
* remove 删除首个符号条件的元素
  * ls.remove('woman')

###  3 列表切片

* 获取多个元素的值
  * ls[0:2]
* 通过步长截取
  * ls[start_index:end_index:step]
* 花式用法
  * ls[::-1]  list的倒叙

### 4 列表常用运算

* +与*列表的算术运算
  * 连接两个列表使用+，重复复制多个列表使用*
    * l1 = [1, 2, 3] + ['a', 'b', 'c']
    * l2 = ['hello'] * 3
  * in成员运算
    * in判断一个元素是否在列表中，存在返回True，否则返回False
    * not in与in相反，判断一个元素不存在列表中

###  5 列表常用函数

* len(list) 返回列表长度
* max(list) 返回列表中元素最大值，必须是同类型对比
* min(list) 返回列表元素最小值，必须是同类型对比
* list(tuple)将元组转换为列表

### 6 list列表常用方法

* list.cout(obj) 統計某个元素在列表中出现的次数
* list.extend(seq) 在列表末尾一次性追加另一个序列中的多个值
* list.index(obj) 在列表中找出第一个匹配项的索引位置
* list.reverse() 反转列表中元素
* list.sort([func]) 对原列表进行排序
* list.clear() 清空列表
* list.copy() 复制列表

