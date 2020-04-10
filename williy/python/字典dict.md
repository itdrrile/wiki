# 字典dict

## 1 访问dict

* 获取dict字典的值
  * dict[key] 如果key存在，dict就返回对应的value，如果key不存在，会抛出KeyError异常
  * dict.get(key, default=None) 在key不存在的时候，返回default值
  * dict.setdefault(key, default=None) 如果键不存在于字典中，将会添加键并将值设为default
* 返回dict字典的所有键keys和所有的值values
  * dict.keys() 返回所有键的可迭代对象
  * dict.values() 返回所有值的可迭代对象

## 2 新增与修改字典的值

* dict[key] = value 新增或修改字典的值
* dict1.update(dict2) 根据dict2字典更新dict1字段，没有的值新增，有的值修改

## 3 删除字段元素

* dict.pop(key) 删除对应键值，返回值为被删除的值
* dict.clear() 清空dict
* del dict[key] 删除对应键值
* del dict 删除dict，dict无法访问

## 4 字典遍历

* 通过key遍历

  for key in dict

* 通过dict.items遍历

## 5 字典排序

* sorted(d.items(), key=lambda item:item[1], reverse=True) 根据值进行排序
* sorted(d.items(), key=lambda item:item[0]) 根据键进行排序

## 6 key和value的类型

键key：都必须是哈希的，不可变的数据类型才可以做字段中的键(list/dict/set不可以用做键，但tuple可以)

值value：没有任何限制，任何数据类型都可以

