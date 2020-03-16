## linux常用命令

### 1 ls

* 常用参数
  * -a 列出目录下所有文件，包括隐藏文件
  * -R 递归处理
  * -t 用文件和目录的更改时间排序
  * -l 显示详细信息

### 2 日期的遍历

```bash
start=$1
end=$2
while [ "$start" != "$end" ]
do
echo $first
let first=`date -d "-1 days ago ${first}" +%Y%m%d`
done
```

### 3 shell脚本并行执行

正常情况下，shell脚本是串行执行的，一条命令执行完才会执行接下来的命令，如果命令之间没有互相依赖关系时，可以让命令并行执行，并行执行的方法就是在命令后加上&符号

```bash
# !/bin/bash
for i in `seq 1 10` 
do
    echo $i &
done
```

这样不能保证命令的执行顺序，有时候需要保证for循环所有命令执行完后再向后执行接下来的命令，可以使用wait实现

```bash
# !/bin/bash
for i in `seq 1 10` 
do
    echo $i &
done
wait
```

### 4 vim

* 1) 光标的移动
  * ctrl + f 向下移动一页
  * ctrl + b 向上移动一页
  * crtl + d 向下移动半页
  * ctrl + u 向上移动半页
  * 0 移动到这一行最前面字符
  * $ 移动到这一行最后面字符
  * G 移动到文件的最后一行
  * nG 移动到文件的第n行
  * gg 移动到文件的第一行
  
* 2）字符串的查找和替换
  * /word 向光标之下寻找一个名为word的字符串
  * ?word 向光标之上寻找一个名为word的字符串
  * :n1,n2s/word1/word2/g 在n1和n2之间寻找word1这个字符串，并替换为word2
  * :1,$s/word1/word2/g 在第一行和最后一行之间寻找word1这个字符串，并替换为word2
  
* 3） 复制、删除、粘贴
  
  * dd 删除光标所在的那一整行
  * d1G 删除光标所在到第一行的数据
  * dG 删除光标所在到最后一行的数据
  * yy 复制光标所在行
  * p 将复制的数据在光标下一行粘上
  * P 将复制的数据在光标上一行粘上
  
* 内容的复原
  * u 复原前一个动作
  * ctrl + r重做上一个动作

* 多文件编辑

  vim后面可以接好几个文件来打开

  * n 编辑下一个文件
  * N 编辑上一个文件
  * :files 列出目前vim打开的所有文件
  
* 窗口分区显示

  * : sp filename 打开一个新的窗口
  * ctrl + w + j/ctrl + w + ⬇ 光标可以移动到下方窗口
  * ctrl + w + k/ctrl + w + ⬆ 光标可以移动到上方窗口

* window和Linux的断行符转换

  * dos2unix [-kn] file [newfile]
  * unix2dos [-kn] file [newfile]
    * -k 保留文件原本的mtime时间格式
    * -n 保留原本的旧文件，将转换后的文件输出到新文件

### 5 tar

* 参数
  * -c 创建打包文件
  * -t 察看打包文件的内容有哪些文件
  * -x 解打包或解压缩功能，可以搭配-C在特定目录解开
  * -z 通过gzip的支持进行压缩/解压缩，此时文件名最好为*.tar.gz
  * -j 通过bzip2的支持进行压缩/解压缩，此时文件名最好为*.tar.bz2
  * -v 在压缩/解压缩的过程中，将正在处理的文件名显示出来
  * -f 后面要立刻接要被处理的文件名
  * -C 这个选项用在解压缩，若要在特定目录解压缩，可以使用这个选项
  * -p 保留备份数据的原本权限与属性，常用于备份重要的配置文件
  * -P 保留绝对路径，即允许备份数据中含有根目录存在之意
  * --exclude=FILE：在压缩的过程中，不要将FILE打包

### 6 cut

这个指令是以行为单位的

* cut -d '分割字符' -f fields
  * echo ${PATH};cut -d ':' -f 5
  * echo ${PATH};cut -d ':' -f 3,5
* cut -c 字符区间
  * export ${PATH}; cut -c 12-

### 7 grep

* 选项与参数
  * -a 将binary文件以text文件的方式搜寻数据
  * -c 计算找到'搜寻字符串'的次数
  * -i 忽略大小写的不同
  * -n 顺便输出行号
  * -v 反向选择

### 8 sort

* 选项与参数
  * -f 忽略大小写的差异
  * -b 忽略最前面的空白字符部分
  * -M 以月份名称来排序
  * -n 以纯数字排序
  * -r 反向排序
  * -u 就是uniq，相同数据中仅出现一行
  * -t 分割符号，默认是用 [tab] 键来分割
  * -k 以哪个区间来进行排序
* 例  
  * cat /etc/passwd | sort -t ':' -k 3|wc -l

### 9 uniq

* 选项与参数
  * -i 忽略大小写字符的不同
  * -c 进行计数

### 10 wc

   wc [-lwm]

* -l 仅列出行数
* -w 仅列出多少字
* -m 多少字符

### 11 tee

* tee会同时将数据流分送到文件去与屏幕

* 用法： tee [-a] file

* 选项与参数：

  -a：以累加的方式，将数据加入file中

### 12 文件夹的遍历

```bash
root_dir=/ssd/lyang
for sub_dir in `ls $1`
do
    if [ -d $sub_dir ]
    then
        echo "is dir"
    else
        echo "is file"
    fi
done
```









