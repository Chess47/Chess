# ChessPy
> William and Marco

[TOC]

## 0. 学习目标

1. 学会使用git作为团队协作开发。

2. 能够学会多人协作，项目管理方式。

   > XD.为了预防35岁就被优化，学点项目项目、产品等知识应该也是有帮助的。

3. 养成记录文档的习惯，有好的资料大家都可以放上来。

4. 完成中国象棋-python程序。cpp可供参考

5. 制作象棋AI。



## 1. 需求文档

> 因为大家都可能有自己的事情要忙，我这里建议实行责任认领制。关于待实现的需求、待解决的bug大家采用认领的方法，即谁爱做就谁做。
>
> ==PS：纯业余项目，不要给自己压力。以学习交流为主==
>
> * 认领方式在下面备注自己的名字就好了。
> * 每次都要新建一个分支，待完成后，再合并到已有的项目。
> * 如果比较难做，可多人共同认领一个需求/bug。两个人在同一个分支，协调来做。
> * 

**需求**

- [ ] 实现象棋功能。

- [ ] 加入AI

  - [ ] 搜索-评估方法

    - [ ] 使用Minmax、alpha-beta等方法搜索

      > [参考资料-蒙特卡洛书和模仿alpha Go的](https://github.com/Trussin/Chinese-Chess-AI)

  - [ ] 强化学习(Alpha GO那套)

    > [参考资料-中国象棋AlphaZero](https://github.com/bupticybee/icyChessZero)
    >
    > [参考资料-cchess-zero](https://github.com/chengstone/cchess-zero)

- [ ] 加入网络对战功能，部署到服务器上。

  > 我有一个云服务器，可以拿来搭建web，部署在web上。

- [ ] 不同象棋AI进行博弈。

## 2. TODOlist

**bug**

- [ ] 将军之后不会结束游戏  –marco

- [ ] 走棋之后,有时候会出现bug.开局双方都架炮,都不架马,然后提卒.另一方就不能走了.应该是在gamerule里面。

**Feature**

- [ ] 加入提醒功能,提醒现在是谁走. –marco
- [ ] 点击棋子,有标注提醒选择了哪个棋子
- [ ] 加入声音
- [ ] 加入AI
- [ ] 换个界面



# 附录

下面介绍一些工具的tutorial，这些工具在多人协作开发会有很多好处。

## 1. git指南

[参考资料-廖雪峰](https://www.liaoxuefeng.com/wiki/896043488029600)

**准备**

1. 安装git
2. 配置ssh

------

**提交**

1. 远程检出仓库(下载仓库) 

   `git clone username@host:/path/to/repository`        

2. 添加到缓存区

   `git add <filename>`

   > 也可以git add .表示提交当前目录所有文件到缓存区

3. 提交到本地仓库的HEAD中

   `git commit -m "注释" `

4. 推送改动，将本地修改到远端仓库

   `git push origin master`

------

**更新**

1. follow别人的改动，更新仓库

   `git pull`

------

**分支**

没用过，研究了再说



## 2. markdown

> markdown 是一种轻量级标记语言，类似于html，latex。但语法要求更简单，推荐使用typora文件打开.md文件。
>
> 在企业，项目开发的文档多用md编写。不到一个小时可基本掌握基本语法。

[参考资料-github文档](https://github.com/younghz/Markdown)

[参考资料-掘金-markdown学习](https://juejin.im/post/5bbc675bf265da0aeb7120ac)

## 3. 代码质量规范

> 在不违反编译器/解释器等前提下，实现同一功能往往有不同写法。因此为了加强代码可读性，统一代码风格，各项目组或者对应标准委员会都发发布代码风格规范。
>
> * cpp下因为语法自由度高，c98、c11、c20等标准都有在用（生产环境不便更新标准），就比较少标准。
> * java的自由度也高，有很多标准范式。所以好像好多IT学习网站上都有代码风格这一课程资料内容。
> * 而python因为比较新，好像标准范式较为统一。都是PEP8标准。
>   * 而这个PEP8标准常人都是不会去记的，因此一般都是依赖于编辑器的一些插件提醒。自己写的代码，转为符合PEP8规范的这个过程叫**格式化代码**常用的有flake8 和 pylint 。两者都是 Python 的 Linter 工具，都归于 Python 代码质量规范组织（PyCQA，Python Code Quality Authority）旗下。
>   * 我建议我们都使用flake8。
>
> ------
>
> 而一般代码风格规范内容包括
>
> * 命名
> * 注释
> * 缩进
> * ……

[参考资料-pycharm下格式化代码](https://jingyan.baidu.com/article/455a9950618f7ba16627788d.html)

[参考资料-vsc下格式化代码](https://blog.csdn.net/weixin_37930716/article/details/85228844)



## 4. git速度太慢

[linux下，git速度太慢](https://www.cnblogs.com/antble/p/12111234.html)

[windows下，git速度太慢](https://www.cnblogs.com/Laggage/p/10878797.html)



## 5. 梯子

[SSR客户端](https://tlanyan.me/shadowsockr-shadowsocksr-shadowsocksrr-clients/)下载对应版本，打开软件，后打开下面图片，找到扫描屏幕二维码的按钮即可。

![image-20200725003956296](.README.assets/image-20200725003956296.png)