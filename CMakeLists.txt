cmake_minimum_required(VERSION 3.7)
project(redis_server)

set(CMAKE_CXX_STANDARD c++11)

include_directories(
        deps/lua/src
        src
        deps/hiredis
        deps/geohash-int
)

set(SOURCE_FILES
        src/server.c #主函数，初始化
        src/redis-check-rdb.c#redis文件格式检查
        src/geo.c #包含测距，经纬度数组
        deps/geohash-int/geohash.c #geohash计算
        deps/geohash-int/geohash_helper.c #geohash计算

        src/config.c#配置文件的读取
        src/object.c #redis对象
        src/debug.c#debug命令
        src/syncio.c #同步io
        src/rand.c#随机数生成

        src/util.c#工具类，正则表达式、内存显示、longlong与文字的胡转
        src/aof.c#aof文件操作，包含fork后台备份

        src/sha1.c#sha1算法
        src/cluster.c
        src/replication.c#同步复制
        src/db.c#内存数据库的操作
        src/multi.c#多命令,使用监控方法实现事物

        src/blocked.c#客户端阻塞类

        src/pubsub.c#发布和订阅
        src/t_zset.c#跳跃list
        src/t_list.c#list,链表
        src/t_hash.c#hash操作
        src/t_set.c#set集合操作
        src/t_string.c#基础set/get操作命令

        src/dict.c#hasbtable实现
        src/quicklist.c#快速list，节点包含ziplist，支持顺序
        src/adlist.c#基础链表list
        src/sparkline.c#画线
        src/intset.c#整数集合
        src/endianconv.c

        src/sort.c#对储存的数据进行排序
        src/pqsort.c#快速排序实现方法

        src/notify.c#命令事件通知
        src/memtest.c
        src/lzf.h
        src/lzf_c.c
        src/lzf_d.c
        src/latency.c

        src/setproctitle.c
        src/zipmap.c #压缩的map
        src/ziplist.c #压缩的list
        src/zmalloc.c #内存申请释放封装
        src/slowlog.c
        src/hyperloglog.c#基数统计
        src/bitops.c
        src/sentinel.c

        src/rdb.c#持久化文件读取到内存的操作
        src/bio.c #后台文件io
        src/rio.c#redis IO操作
        src/anet.c #socket操作封装
        src/ae.c #ae事件驱动库
        src/networking.c#网络工具类

        src/scripting.c
        src/release.c

        src/crc16.c#crc16实现
        src/crc64.c#crc64实现
        )

LINK_DIRECTORIES(/usr/local/lib deps/lua/src deps/hiredis)

add_executable(redis_server ${SOURCE_FILES} ${cpp_lua} ${cpp_hiredis} ${geohash_int})

target_link_libraries(redis_server lua hiredis m pthread c dl)


project(redis_test)
set(CMAKE_CXX_STANDARD c++11)

add_executable(redis_test test.c src/pqsort.c deps/geohash-int/geohash.c)