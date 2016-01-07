# XunLongJi Mobile Server

`XunLongJi Mobile Server` (也称作GameServer)存在的首要目的是为了把原来的用 `Native C++` 写的GameServer服务器改成分布式架构,
方便扩展以承载更多的人数.

## 承担的功能

* 客户端(Client)的连接入口,即玩家从这里开始登陆到服务器
* 在服务器端,它提供对其它功能模块(如排行,数据库访问,副本开启等)的访问职责
* 处理一些需要直接与玩家面对面处理的逻辑,如玩家上线,下线等

## 使用 `c++/cli` 架构的原因
* 复用原来已经写完的大量的C++功能
*  使用C#语言
    - 使用成熟且功能强大的 `Orleans` 分布式架构
    - c#写某些对性能要求不高的功能会更快速,且不容易出错
*  一些对性能要求特别高的功能还可以继续使用 `Native C++` 来实现

> 为了最大化利用物理机器的内存,需要实现 `64位` 版本

### [注意:]()
如果需要依赖其它的静态库,则要注意:
* Basically, with mixed mode .NET apps, you need to make sure all statically linked libs are compiled with /EHa instead of the default /EHs.
否则可能会带来内存的慢慢封增长