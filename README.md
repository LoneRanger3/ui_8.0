# 开发环境搭建

## Ubuntu

### 编译安装CrLog日志库

下载拉取源码：

```
git clone http://172.23.88.26:3333/zhangyufeng/libcrlog.git
```

按照文档说明编译安装使用。



### 编译安装json-c库

官方仓库：https://github.com/json-c/json-c

直接安装ubuntu系统官方源提供的版本，在ubuntu16.04中，libjson-c-dev的版本为0.11。

```
sudo apt install libjson-c-dev 
```



### 编译安装protobuf-c

官方仓库：https://github.com/protobuf-c/protobuf-c

直接安装ubuntu系统官方源提供的版本，在ubuntu16.04中，libprotobuf-c-dev、protobuf-c-compiler的版本是1.2.1，libprotobuf-dev、protobuf-compiler的版本是2.6.1。

```
sudo apt install protobuf-compiler protobuf-c-compiler libprotobuf-dev 
```



### 编译整个项目

```
make clean && make -j4
```

编译成功后，得到各个server的可执行程序，单独运行即可测试。



# 关于源码

### 命令字定义

1、进程间使用，命令字在“global/Global.h”中的“GlobalMsgCmd”定义，值范围是0~4096   
2、进程内使用，命令字在进程中“Base/(xx)MsgBase.h”中的“MsgCmd”定义，值范围是4096~（进程内线程使用）

### protobuf定义
1、进程间使用，在“global/SystemProto/SystemServer.proto”中定义   
2、进程内使用，在“Base/Proto/~Server.proto”中定义（进程内线程使用）   
3、编译protobuf命令：protoc-c --c_out=./ 文件名.proto   
4、修改protobuf中string为bytes，后面传递字符串统一使用（bytes）

### 核心线程打印机状态共享
1、使用“Base/ShareState/ShareState.c”创建静态变量，通过接口全局调用   
2、大部分线程是不允许修改打印机状态，只可以获取；在“Base/ShareState/ShareState.h”定义获取接口

### 各服务进程使用U盘、SD卡路径
1、U盘拔插等情况，路径会动态更新   
2、不可使用GetUserLocalUdiskPtah()、GetUserLocalSdCardPtah()获取路径   
3、主进程通过状态同步到服务进程，使用uDiskPath、sdPath获取路径

### 保持日志功能正常
1、在不同平台协同开发，平台环境不支持Crlog，可以将（global/CrlogDef.h）添加到自己的环境中   
2、（global/CrlogDef.h）已将Crlog接口重定义为标准输出（printf）   
3、开发过程设置（ENABLE_USE_CRLOG = 0）   
4、提交代码设置（ENABLE_USE_CRLOG = 1），并在目标板上确认日志正常   
5、日志解压密码由 LOG_DECOMPRESSION_PASSWORD 宏定义

### 开发调试方式
1、在板子用户数据保存区里的“creality/userdata”目录下，创建“debug_mode”文件，开启调试   
2、klipper远程调试；板上创建一个"tcp server", 监听 KLIPPER_SOCKET_PORT 端口，转发klipper数据到PC端；将 KLIPPER_SOCKET_ADDR 修改成板子的IP，既可以在PC上调试应用程序   
3、模拟交互指令；板上创建一个"udp server", 监听 UDP_TEST_SERVER_PORT 端口；在没有人间人机交互时（UI、APP）时，可以使用UDP广播给master进程发送交互指令（指令按照实际需要补全，指令定义规范，新增指令可以直接上传，方便所有开发人员使用）   
4、裸板调试，在板子用户数据保存区里的“creality/userdata”目录下，创建“stop_error”文件关闭屏幕错误弹窗，方便硬件调试

### AI功能
1、意面检测数据收集，在配置文件“user_print_refer.json”中打开AI数据收集开关“dataCollect”   

### 产测开发
1、在板子用户数据保存区下创建“factory_test”文件，重新启动进入产测模式   
2、显示进程通过“isFactoryTest()”判断当前是否在产测模式，处理业务逻辑   
3、显示进程通过“isMachineTest()”判断当前是否在整机产测模式，处理业务逻辑   
4、其他进程无需判断是否进入产测   

### 服务器环境选择
1、UI修改设备部署环境（正式、预发布、测试、联调），重启生效   
2、通过时区、语言；区分国内、海外服务器   
3、UI“关于本机”页面，连续点击“MAC地址”出弹窗，切换服务器   

### 降版本功能说明
1、不同机型降版本限制，可以在“SysConfig.h”文件，参照K1机型增加、修改版本限制