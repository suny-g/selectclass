# selectclass
creatr by Luojianqiu 2026,1,11

该程序我将其设计为4个分区,分别为以下几个：

1.表现层Presentation Layer，该模块实现与用户的交互界面

2.应用逻辑层Application Layer,该模块分别为学生，老师，以及教学秘书提供控制器，方便调用领域层的操作

3.领域层Domain Layer，该模块是老师，学生，教学秘书以及课程类的具体操作的实现，是整个程序的核心

4.数据管理层Data Access Layer, 该模块是管理数据库的模块分区，其调用者应当为教学秘书类的对象

最后的程序演示视频放在了代码文档中
