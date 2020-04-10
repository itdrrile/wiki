## 1 度量学习

### 1） 定义

* 度量学习是一种空间映射的方法，能够学习到一种特征(Embedding)空间，在此空间中，所有的数据都被转换成一个向量，并且相似样本的特征向量之间距离小，不相似样本的特征向量之间距离大，从而对数据进行区分
* 在深度学习中，很多度量学习的方法都是使用成对成对的样本进行loss计算的，这类方法被称为pair-based deep metric learning

### 2）常见的度量损失函数

* Contrastive loss

  * 选取一对样本对，如果其是正样本对，则产生的loss就应该等于其特征之间的距离

  * 如果是负样本对，它们之间的距离应该大于设定的阈值m

  * 损失函数如下：

    ![image-20200320141402290](C:\Users\WangLiyun\AppData\Roaming\Typora\typora-user-images\image-20200320141402290.png)

  * contrastive loss能够让正样本尽可能的接近，负样本尽可能的远离，这样可以增大类间距离，减小类内差异。但是其需要指定一个固定的margin，即公式中的m，因为m是固定的，所以这里就隐含了一个很强的假设，即每个类目的岩本分布都是相同的，不过一般情况下这个强假设未必成立

* Triplet loss

  * Triplet Loss的思想是让负样本对之间的距离大于负样本对之间的距离

  * 首先选取一个样本，此样本称之为anchor样本，然后选取一个与anchor样本同类别的样本，称之为positive，并让其与anchor样本组成一个正样本对；再选取一个与anchor不同类别的样本，称之为negative，让其与anchor样本组成一个负样本对，这样一共就选取了三个样本，即triplet

  * 损失函数如下：

    ![image-20200320142720107](C:\Users\WangLiyun\AppData\Roaming\Typora\typora-user-images\image-20200320142720107.png)

* Triplet center loss

  * Triplet loss是让正样本对之间的距离小于负样本对之间的距离，并且存在一定的margin。因此triplet样本的选取至关重要，如果选取的triplet对没啥难度，很容易区分，那大部分时间生成的loss都为0，模型不更新，而如果使用hard mining的方法对难例进行挖掘，又会导致模型对噪声极为敏感。为了对Triplet loss的缺点进行改进，Triplet center loss就被提出来了

  * Triplet center loss的思想非常简单，原来的Triplet是计算anchor到正负样本之间的距离，现在Triplet center是计算anchor到正负样本所在类别的中心的距离。

  * Triplet center loss形式如下：

    ![image-20200320144252068](C:\Users\WangLiyun\AppData\Roaming\Typora\typora-user-images\image-20200320144252068.png)

* N-pair loss

  * triplet loss同时拉近一对正样本和一对负样本，这就导致在样本选取时，当前样本对只能够关注一对负样本对，而缺少对其他类别样本的区分能力

  * N-pair loss就选取了多对负样本对，即一对正样本对，选取其它所有不同的类别的样本作为负样本与其组合得到负样本对。如果数据集中有N个类别，则每个正样本对都对应了N-1个负样本对

    ![image-20200320145143689](C:\Users\WangLiyun\AppData\Roaming\Typora\typora-user-images\image-20200320145143689.png)

  * N-pair loss的形式如下：

    ![image-20200320145258782](C:\Users\WangLiyun\AppData\Roaming\Typora\typora-user-images\image-20200320145258782.png)

* Quadruplet loss

  * Quadruplet loss由两部分组成：

    * 一部分是正常的Triplet loss，这部分loss能够让模型区分出正样本和负样本对之间的相对距离

    * 另一部分是正样本对和其它任意负样本对之间的距离。这一部分约束可以理解为最小的类间距离都要大于类内距离，不管这些样本对是否有同样的anchor。即不仅要要求A1A2 < A1B1，还要要求A1A2 < B1C1

    * Quadruplet loss的形式如下：

      ![image-20200320150128702](C:\Users\WangLiyun\AppData\Roaming\Typora\typora-user-images\image-20200320150128702.png)

* Lifted Structure Loss

  * Lifted Structure loss的思想是对于一对正样本对而言，不去区分这个样本对中谁是anchor，谁是positive，而是让这个正样本对中的每个样本与其它所有负样本的距离大于给定的阈值。此方法能够充分的利用min-batch中的所有样本，挖掘出所有的样本对。

  * Lifted Structure Loss的形式如下：

    ![image-20200320150517481](C:\Users\WangLiyun\AppData\Roaming\Typora\typora-user-images\image-20200320150517481.png)

    