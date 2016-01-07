# XunLongJi Mobile Server

`XunLongJi Mobile Server` 存在的首要目的是为了把原来的用 `Native C++` 写的GameServer服务器改成分布式架构,
方便扩展以承载更多的人数.

使用 `c++/cli` 架构
* 复用原来已经写完的大量的C++功能
*  使用C#语言
    - 使用成熟且功能强大的 `Orleans` 分布式架构
    - c#写某些对性能要求不高的功能会更快速,且不容易出错
*  一些对性能要求特别高的功能还可以继续使用 `Native C++` 来实现

> 为了最大化利用物理机器的内存,只实现 `64位` 版本