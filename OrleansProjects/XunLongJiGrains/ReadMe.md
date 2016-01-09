# XunLongJi Grains
实现各种各样的 `Grain` ,如角色存档的性能优化的 Grain, 匹配比赛用的 Grain 等.

**注意:**
- 使用 `C#` 来编码,以更方便的实现逻辑,因为 `C#` 在做异步编程时非常容易,一些对性能要求特别高的逻辑,可以考虑使用封装到 `C++` 的 `Dll` 中来调用.
- 直接使用 `OrleansHost.exe` 来启动 `Grains`,不需要单独的进程,这样更方便扩展到其它形式的 `Soil`,如 `Microsoft Azure`
