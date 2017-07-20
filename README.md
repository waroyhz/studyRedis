这是一个学习项目，基与redis3.2.9，用于分析redis源码，并根据学习进度加入注释。

文件部分整理：

         #检测类
         src/memtest.c #内存测试
         src/redis-check-rdb.c#redis文件格式检查
 
         #数据结构
         src/object.c #redis对象
         src/t_zset.c#跳跃list
         src/t_list.c#list,链表
         src/t_hash.c#hash操作
         src/t_set.c#set集合操作
 
         src/dict.c#hasbtable实现
         src/adlist.c#基础链表list
         src/intset.c#整数集合
         src/zipmap.c #压缩的map
         src/ziplist.c #压缩的list
         src/quicklist.c#快速list，节点包含ziplist，支持顺序
 
         #数据库
         src/aof.c#aof文件操作，包含fork后台备份
         src/db.c#内存数据库的操作
         src/rdb.c#持久化文件读取到内存的操作
         src/bio.c #后台文件io
         src/rio.c#redis IO操作
 
         #数据操作
         src/debug.c#debug命令
         src/pubsub.c#发布和订阅
         src/multi.c#多命令，事务,使用监控方法实现事物
         src/slowlog.c#showlog命令
         src/bitops.c#位操作
         src/t_string.c#基础set/get操作命令 
 
         #工具
         src/config.c#配置文件的读取
         src/geo.c #包含测距，经纬度数组
         deps/geohash-int/geohash.c #geohash计算
         deps/geohash-int/geohash_helper.c #geohash计算
         src/util.c#工具类，正则表达式、内存显示、longlong与文字的胡转
         src/rand.c#随机数生成
         src/sparkline.c#画线
 
         #事件
         src/ae.c #ae事件驱动库
         src/notify.c#命令事件通知
         src/blocked.c#客户端阻塞类
 
         #主程序
         src/server.c #主函数，初始化
 
 
         #网络
         src/anet.c #socket操作封装
         src/networking.c#网络工具类
         src/cluster.c #集群
         src/replication.c#同步复制
 
         #封装
         src/syncio.c #同步io
         src/zmalloc.c #内存申请释放封装
         src/scripting.c#lua命令实现
         src/endianconv.c#高低字节转换工具
 
         #算法
         src/sort.c#对储存的数据进行排序
         src/pqsort.c#快速排序实现方法
         src/hyperloglog.c#基数统计
         src/sha1.c#sha1算法
         src/crc16.c#crc16实现
         src/crc64.c#crc64实现
 
 
         #其他:
         src/lzf.h
         src/lzf_c.c
         src/lzf_d.c
         src/latency.c
         src/setproctitle.c
         src/sentinel.c
         src/release.c

