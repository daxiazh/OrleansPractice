# XunLongJi Grains
实现各种各样的 `Grain` ,如角色存档的性能优化的 Grain, 匹配比赛用的 Grain 等.

## 启动 `Soil` 的方法
直接执行输出目录下的 `OrleansHost.exe` (如 `bin\Debug\OrleansHost.exe` 或 `bin\Release\OrleansHost.exe` ), 即可启动一个 `Soil` (即传统意义上叫的 `服务器` ). `OrleansHost.exe` 会自动查找它所在目录下的所有实现了 `Grain` 的 `Dll` 并加载它们,以保证所有的 `Grain` 可以正常访问.

## 配置文件
- OrleansConfiguration.xml -- 配置一些 `Soil` 通用及本节点的配置
- OrleansHost.exe.config -- 配置 `OrleansHost.exe` 程序一些全局配置,基本不需要再修改它,除非影响到性能.
- 各个配置项功能的说明在 `OrleansConfiguration.xsd` 文件中,直接使用 VS 打开即可方便的查看每一个配置参数的说明
- 如何配置集群等,具体请查看 [Typical Configurations](http://dotnet.github.io/orleans/Orleans-Configuration-Guide/Typical-Configurations).下面是部分说明摘取

  **Local Development**

  For local development, where there is only one silo running locally on the programmer's machine, the configuration is already included in the SDK. The local silo that can be started with the StartLocalSilo.cmd script in the top Orleans SDK folder is configured as follows.

  ```xml
  <OrleansConfiguration xmlns="urn:orleans">
    <Globals>
      <SeedNode Address="localhost" Port="11111" />
    </Globals>
    <Defaults>
      <Networking Address="localhost" Port="11111" />
      <ProxyingGateway Address="localhost" Port="30000" />
    </Defaults>
  </OrleansConfiguration>
  ```

  To connect to the local silo, the client needs to be configured to localhost and can only connect from the same machine.

  ```xml
  <ClientConfiguration xmlns="urn:orleans">
    <Gateway Address="localhost" Port="30000"/>
  </ClientConfiguration>
  ```

  **Reliable Production Deployment Using ZooKeeper**

  For a reliable production deployment using ZooKeeper, you need to use the ZooKeeper option for cluster membership. This configuration is typical of deployments to on-premise servers.

  The format of the DataConnection string is documented in the ZooKeeper Programmer's Guide. A minimum of 5 ZooKeeper servers is recommended.

  ```xml
  <?xml version="1.0" encoding="utf-8"?>
  <OrleansConfiguration xmlns="urn:orleans">
    <Globals>
      <SystemStore SystemStoreType="ZooKeeper"
                    DeploymentId="<your deployment ID>"
                    DataConnectionString="<<see comment above>>"/>
    </Globals>
    <Defaults>
      <Networking Address="localhost" Port="11111" />
      <ProxyingGateway Address="localhost" Port="30000" />
    </Defaults>
  </OrleansConfiguration>
  ```

  Clients need to be configured to use ZooKeeper for discovering the gateways, the addresses of the Orleans servers are not statically known to the clients.

  ```xml
  <?xml version="1.0" encoding="utf-8" ?>
  <ClientConfiguration xmlns="urn:orleans">
    <SystemStore SystemStoreType="ZooKeeper" DeploymentId="target deployment ID" DataConnectionString="<<see comment above>>"/>
  </ClientConfiguration>
  ```

  **Unreliable Deployment on a Cluster of Dedicated Servers**

  For testing on a cluster of dedicated servers when reliability isn't a concern you can leverage MembershipTableGrain and avoid dependency on Azure Table. You just need to designate one of the nodes as a Primary.

  ```xml
  <OrleansConfiguration xmlns="urn:orleans">
    <Globals>
      <SeedNode Address="<primary node>" Port="11111" />
      <Liveness LivenessType ="MembershipTableGrain" />
    </Globals>
    <Defaults>
      <Networking Address=" " Port="11111" />
      <ProxyingGateway Address=" " Port="30000" />
    </Defaults>
  </OrleansConfiguration>
  ```

  For the client:

  ```xml
  <ClientConfiguration xmlns="urn:orleans">
    <Gateway Address="node-1" Port="30000"/>
    <Gateway Address="node-2" Port="30000"/>
    <Gateway Address="node-3" Port="30000"/>
  </ClientConfiguration>
  ```

## 注意:
- 使用 `C#` 来编码,以更方便的实现逻辑,因为 `C#` 在做异步编程时非常容易,一些对性能要求特别高的逻辑,可以考虑使用封装到 `C++` 的 `Dll` 中来调用.
- 直接使用 `OrleansHost.exe` 来启动 `Grains`,不需要单独的进程,这样更方便扩展到其它形式的 `Soil`,如 `Microsoft Azure`
- 通过修改 `.nuget\NuGet.Config` 文件中的 `packageSources` 项来更改依赖包的获取路径
- 如果缺少依赖库,可以先编译 `Orleans`,让它把相关的 `Package` 下载下来,然后包含它下载的目录即可解决我们的依赖
