From https://notes.sshwy.name/Interactive-Prob-Judger/

# 为什么会有这篇文章
交互题是 OI 中一种新颖的题型。它可以同时恶心出题人和做题的人。

出题人写交互器要调试半天，做题的人写代码不方便本地评测。

在花费一些时间后，我实现了一个简单的交互器运行模块，可以帮助你进行交互题的本机评测。

如果你并不知道交互题是什么，建议你先去做一道交互题。

如果你还不了解交互题的造题过程，请在 Polygon 上注册一个帐号，观摩一下它默认提供的 example-interactive-binary-search。

# 用途
交互题包含几个部分：

- 交互器（交互库）：这个是出题人实现的，用于和你提交的程序进行交互。如果要本地评测你代码的正确性，那么显然你得自己写一个交互器。不过大多数题目的交互器是不难实现的。
- 数据生成器：交互题仍然是有数据的。交互器大部分读入数据之后才会给你的程序提供输入，监听你程序的输出。这个也是自己写的。
- 评测器：这是本文实现的内容。如果没有评测器，那么你本地测试就只能开两个终端窗口，每次把交互器的窗口输出的内容复制到你程序的窗口，再把你程序的输出复制到交互器的窗口，无法实现自动化。更别提对拍了。
形象地说，评测器是交互器和你程序的桥梁。

# 执行
```
$ g++ a.cpp -o a
$ g++ interactor.cpp -o interactor
$ g++ judger.cpp -o judger
$ echo 5 10 > in.txt
$ ./judger ./a ./interactor
a.cpp: n 10
? 6
b.cpp: x:[?], y:[6]
? 3
b.cpp: x:[?], y:[3]
? 4
b.cpp: x:[?], y:[4]
? 5
b.cpp: x:[?], y:[5]
b.cpp: x:[!], y:[5]
AC
```