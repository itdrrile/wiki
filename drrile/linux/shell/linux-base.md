# Linux常用命令

>- 常见命令格式： **命令 [-选项] [参数]**
>- 多个选项可以写在一起，如 **-l -a** 可以写成 **-la**
>- 简化选项与完整选项：如 **-a** 的完整选项为 **--all**



## 目录处理命令

- ls： **l**i**s**t

  - 命令所在路径：/bin/ls

  - 执行权限：所有用户

  - ls **-a** 显示出所有文件，包含隐藏文件

    > Linux中，前缀为**.**的文件即为隐藏文件。将一个文件变为隐藏文件，只需在文件名前加**.**

  - ls **-l** 显示详细信息

    ```shell
    itdrrile@T480:/home/git/wiki$ ls -l
    total 52
    -rwxrwxrwx 1 root     root        26 3月  28 20:15 _config.yml
    drwxr-xr-x 4 itdrrile itdrrile  4096 6月  21 16:29 drrile
    -rwxrwxrwx 1 root     root     35149 3月  28 20:15 LICENSE
    -rwxrwxrwx 1 root     root       128 3月  28 20:15 README.md
    drwxr-xr-x 5 itwilliy itwilliy  4096 6月  21 16:29 williy
    ```

    - 第1列：drwxr-xr-x 

      > d：文件类型（**-**文件、 **d**目录、 **l**软链接文件）
      >
      > rwx：**所有者**(u)权限，r读、w写、x执行
      >
      > r-x：**所属组**(g)权限，r读、w写、x执行
      >
      > r-x：**其它人**(o)权限，r读、w写、x执行

    - 第2列：4，文件引用数

    - 第3列：itdrrile，文件的所有者

    - 第4列：itdrrile，文件的所属组

    - 第5列：4096，文件大写，默认为字节。可以使用**-h**更直观的显示，如下

      ```shell
      itdrrile@T480:/home/git/wiki$ ls -lh
      total 52K
      -rwxrwxrwx 1 root     root       26 3月  28 20:15 _config.yml
      drwxr-xr-x 4 itdrrile itdrrile 4.0K 6月  21 16:29 drrile
      -rwxrwxrwx 1 root     root      35K 3月  28 20:15 LICENSE
      -rwxrwxrwx 1 root     root      128 3月  28 20:15 README.md
      drwxr-xr-x 5 itwilliy itwilliy 4.0K 6月  21 16:29 williy
      ```

    - 第6、7、8列：6月  21 16:29，文件（目录）最近修改时间

      > 注：Linux系统中无文件创建时间概念

    - 第9列：drrile，文件（目录）名称

  - ls -ld 显示查看目录的详细信息（**-d**指查看目录属性），如

    ```shell
    itdrrile@T480:/home/git/wiki$ ls -ld /home/git/wiki/
    drwxrwxrwx 5 root root 4096 3月  28 20:15 /home/git/wik
    ```

  - ls **-i** 显示文件（目录）的i节点(iNode)，如

    ```shell
    itdrrile@T480:/home/git/wiki$ ls -li
    total 52
    2632602 -rwxrwxrwx 1 root     root        26 3月  28 20:15 _config.yml
    2632603 drwxr-xr-x 4 itdrrile itdrrile  4096 6月  21 16:29 drrile
    2632589 -rwxrwxrwx 1 root     root     35149 3月  28 20:15 LICENSE
    2632591 -rwxrwxrwx 1 root     root       128 3月  28 20:15 README.md
    3022310 drwxr-xr-x 5 itwilliy itwilliy  4096 6月  21 16:29 williy
    ```

- mkdir：**m**a**k**e **dir**ectories

  - 命令所在路径：/bin/mkdir
  - 执行权限：所有用户
  - mkdir /tmp/aaa   在已存在的目录下创建一个目录
  - mkdir -p /tmp/aaa/bbb/ccc   递归创建多个目录
  - mkdir /tmp/aaa /tmp/bbb /tmp/ccc  同时创建多个目录
  - mkdir -p /tmp/aaa/xxx/1/2/3 /tmp/aaa/yyy/1/2/3 /tmp/aaa/zzz/1/2/3    同时创建多个递归目录

- cd：**c**hange **d**irectory

  - 命令所在路径：shell内置命令
  - 执行权限:所有用户

- pwd：**p**rint **w**orking **d**irectory

  - 命令所在路径：/bin/pwd
  - 执行权限：所有用户

- rmdir：**r**e**m**ove empty **dir**ectories，删除**空**目录

  > 被删除的目录中不能包含任何文件或者目录

  - 命令所在路径：/bin/rmdir
  - 执行权限：所有用户











## 目录处理命令



