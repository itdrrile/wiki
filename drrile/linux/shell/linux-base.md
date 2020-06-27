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
  
- cp：**c**o**p**y，复制文件或目录

  - 命令所在路径：/bin/cp

  - 执行权限：所有用户

  - 语法：**cp [-选项] [原文件或原目录] [目标目录]**

  - 可以复制多个文件到目标目录

    > cp 文件1 文件2 ... 目标目录

  - 复制目录时使用**-r**选项

    > cp -r 原目录 目标目录

  - 复制后文件保留原文件的属性使用**-p**选项

    > cp -p 原文件 目标目录

  - 修改复制后的文件/目录名称

    > - cp 原文件 目标目录/新文件名
    >
    > - cp -r 原目录目标目录/新目录名

- mv：**m**o**v**e，剪切或更名

  - 命令所在路径：/bin/mv

  - 执行权限：所有用户

  - 语法：**mv [原文件或目录] [目标目录]**

  - 剪切多个文件或目录

    > mv 文件目录1 文件目录2 ... 目标目录

  - 剪切后更名

    > mv **文件目录名** 目标目录/**新文件目录名**

  - **mv会保留文件目录的原属性**

- rm：**r**e**m**ove，移除、删除文件目录

  - 命令所在路径：/bin/rm

  - 执行权限：所有用户

  - 语法：**rm [-选项] [文件或目录]**

  - 删除目录使用选项**-r**

  - 强制执行使用选项**-f**，此时不再出现删除前询问

  - 可以同时删除多个文件

    > rm 文件1 文件2 ...



## 文件处理命令

- touch：创建空文件

  - 命令所在路径：/bin/touch

  - 执行权限：所有用户

  - 语法：**touch [文件名]**

  - Linux文件名中可以使用特殊符号

  - 可以同时创建多个文件

    > touch 文件1 文件2 ...

  - 创建名称中带空格的文件，使用双引号

    > **touch “Program files”**

- cat：显示文件全部内容

  - 命令所在路径：/bin/cat
  - 执行权限：所有用户
  - 语法：**cat [-选项] [文件名]**
  - 显示行号使用选项**-n**

- tac：倒向显示文件全部内容

  - 命令所在路径：/usr/bin/tac
  - 执行权限：所有用户
  - 语法：**tac [文件名]**

- more：分页显示文件内容

  - 命令所在路径：/bin/more

  - 执行权限：所有用户

  - 语法：**more [文件名]**

  - 键盘操作

    > - (空格) 或f   翻页
    > - (Enter)       换行
    > - q或Q          退出

- less：分页显示文件内容，**可向上翻页，可进行搜索**

  - 命令所在路径：/usr/bin/less

  - 执行权限：所有用户

  - 语法：**less [文件名]**

  - 键盘操作

    > - (空格) 或f   翻页
    > - (Enter)       换行
    > - q或Q          退出
    > - (PgUp)       向上翻页
    > - (PgDn)       向下翻页
    > - ↑               向上一行
    > - ↓               向下一行
    > - /keywords 搜索

- head：显示文件前面几行

  - 命令所在路径：/usr/bin/head

  - 执行权限：所有用户

  - 语法：**head [-选项] [文件名]**

  - 指定行数使用选项**-n**，默认10行

    > head -n 20 文件名

- tail：显示文件后面几行

  - 命令所在路径：/usr/bin/tail

  - 执行权限：所有用户

  - 语法：**tail [-选项] [文件名]**

  - 指定行数使用选项**-n**，默认10行

    > tail -n 20 文件名

  - 动态显示文件末尾内容使用选项-f（监控日志）

    > tail -f 文件名



## 链接命令

- ln：**l**i**n**k，生成链接文件

  - 命令所在路径：/bin/ln

  - 执行权限：所有用户

  - 语法：**ln [-选项] [原文件] [目标文件]**

  - 默认为硬链接，软链接使用**-s**选项

    > ln -s idea456/modules.xml modules.xml.soft

  - 软链接与硬链接的区别

    ```shell
    -rw-rw-r-- 2 itdrrile itdrrile  272 6月  18 01:22 modules.xml.hard                                                                   硬链接
    lrwxrwxrwx 1 root     root       19 6月  25 18:09 modules.xml.soft -> idea456/modules.xml                  软链接
    ```

    - 软链接相当于windows中的快捷方式；软链接的文件类型是**l**，而硬链接为文件；软链接文件权限都为**rwxrwxrwx**，但是操作时还是会保留原文件的权限；软链接的大小很小，并不是原文件的大小；软链接使用 **->** 指向原文件，硬链接没有指向

    - 硬链接的效果相当于 **cp -p**，但是修改硬链接的内容会**同步更新**至原文件，修改原文件的内容也会**同步更新**至硬链接

    - **若原文件删除，软链接操作的时候会提示原文件不存在，而硬链接不会**

    - 软链接通过文件类型**l**即可识别，而硬链接需要通过i节点识别，硬链接的i节点与原文件一致

      ```shell
      itdrrile@T480:/learn$ ls -li idea456/modules.xml modules.xml.hard modules.xml.soft 
      786445 -rw-rw-r-- 2 itdrrile itdrrile 272 6月  18 01:22 idea456/modules.xml                                                  原文件
      786445 -rw-rw-r-- 2 itdrrile itdrrile 272 6月  18 01:22 modules.xml.hard                                                         硬链接
      786442 lrwxrwxrwx 1 root     root      19 6月  25 18:09 modules.xml.soft -> idea456/modules.xml        软链接
      ```

    - 相对软链接，硬链接不能跨分区，不能针对目录使用



## 权限管理命令

- chmod：**ch**ange the permissions **mod**e of a file，改变文件或目录权限

  - 命令所在路径：/bin/chmod

  - 执行权限：所有用户

  - 语法：

    - chmod [{ugoa}{+-=}{rwx}] [文件或目录] 

      > - {ugoa}表示用户，u-所属者，g-所属组，o-其它用户，a-全部用户
      > - {+-=}表示权限操作，+ 增加权限，- 去掉权限， = 重新设置权限
      > - {rwx}表示权限类型，r-读权限，w-写权限，x-执行权限

      ```shell
      root@T480:/learn/idea456# chmod u+x,g-w,o=rx modules.xml    多个设置之间使用,连接  [所属者添加执行权限，所属组去掉写权限，其他用户重设为读写权限]
      root@T480:/learn/idea456# chmod a=rwx modules.xml   设置全部用户可读写执行
      ```

    - chmod [mode=421] [文件或目录]

      > r - 4，w - 2，x - 1
      >
      > 无权限为0

      ```shell
      root@T480:/learn/idea456# chmod 755 modules.xml 
      ```

    - 递归修改使用选项**-R**

      ```shell
      root@T480:/learn# chmod -R 755 idea456 
      ```

    - 文件目录权限总结

      | 代表字符 |   权限   |   对文件的含义   |        对目录的含义        |
      | :------: | :------: | :--------------: | :------------------------: |
      |    r     |  读权限  | 可以查看文件内容 |    可以列出目录中的内容    |
      |    w     |  写权限  | 可以修改文件内容 | 可以在目录中创建、删除文件 |
      |    x     | 执行权限 |   可以执行文件   |        可以进入目录        |

- chown：**ch**ange file **own**ership，改变文件或目录的所有者

  - 命令所在路径：/bin/chown
  - 执行权限：所有用户
  - 语法：**chown [用户] [文件或目录]**

- chgrp：**ch**ange file **gr**ou**p** ownership，改变文件或目录的所属组

  - 命令所在路径：/bin/chgrp
  - 执行权限：所有用户
  - 语法：**chgrp [用户组] [文件或目录]**



## 文件搜索指令

- find：文件搜索

  - 命令所在路径：/bin/find

  - 执行权限：所有用户

  - 语法：**find [搜索范围] [匹配条件]**

  - 根据文件名搜索：-name （可以使用通配符，*表示任意多个，?表示任意一个）

    ```shell
    root@T480:/learn# find /learn -name "*123*"
    /learn/idea123
    /learn/123.iml
    root@T480:/learn# find /learn -name "????123"
    /learn/idea123
    ```

  -  根据文件名搜索，不区分大小写：-iname （可以使用通配符，*表示任意多个，?表示任意一个）

    ```shell
    root@T480:/learn# find /learn -iname "wly*"
    /learn/wly
    /learn/wly.txt
    /learn/WLY123.txt
    ```

  - 根据文件大小搜索： -size  （单位为块，块=512B=0.5KB；+n表示大于，-n表示小于，n表示等于）

    ```shell
    root@T480:/learn# find /learn -size -2048                 查找大小小于1M(=2048*0.5KB)的文件目录
    /learn
    /learn/idea123
    /learn/idea123/misc.xml
    /learn/idea123/workspace.xml
    ```

  - 根据所有者搜索：-user 

    ```bash
    root@T480:/learn# find /learn -user itdrrile
    /learn/modules.xml.hard
    /learn/idea456
    /learn/idea456/helloworld.iml
    /learn/idea456/.gitignore
    /learn/idea456/modules.xml
    ```

  - 根据所属组搜索：-group

  - 根据时间属性搜索，（单位为分钟，+n表示超过几分钟，-n表示几分钟内，n表示几分钟）

    - -amin   （访问时间access）
    - -cmin   （文件属性修改change）
    - -mmin （文件内容修改modify）

  - 多个条件搜索

    - 多个条件同时满足： 条件1 **-a** 条件2 **-a** 条件3 **-a** ...   （**a**nd）

      ```bash
      root@T480:/learn# find /learn -size -2048 -a -name "*123*" -a -iname "*wly*"            搜索小于1M且文件名包含123且文件名包含wly不区分大小写的文件目录
      /learn/WLY123.txt
      ```

    - 两个条件满足任意一个：   条件1 **-o** 条件2 **-o** 条件3 **-o** ...    （**o**r）

  - 根据文件类型搜索：-type （f表示文件，d表示目录，l表示软链接文件）

    ```bash
    root@T480:/learn# find /learn -type l
    /learn/modules.xml.soft
    /learn/link.xxx.soft
    ```

  - 根据i节点搜索：-inum 

    - 用于对一些奇怪文件名的操作，如中文乱码等
    - 用于查找硬链接文件

- 

