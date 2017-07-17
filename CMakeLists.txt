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
        src/redis-check-rdb.c
        src/geo.c #包含测距，经纬度数组
        deps/geohash-int/geohash.c
        deps/geohash-int/geohash_helper.c

        src/config.c
        src/object.c #redis对象
        src/debug.c
        src/syncio.c #同步io
        src/rand.c#随机数生成

        src/util.c
        src/aof.c#aof文件操作，包含fork后台备份
        src/rdb.c

        src/sha1.c
        src/cluster.c
        src/replication.c
        src/db.c
        src/multi.c

        src/networking.c
        src/blocked.c

        src/pubsub.c
        src/t_zset.c
        src/t_list.c
        src/t_hash.c
        src/t_set.c
        src/t_string.c
        src/quicklist.c
        src/adlist.c
        src/sparkline.c
        src/intset.c
        src/endianconv.c

        src/sort.c
        src/pqsort.c

        src/notify.c
        src/memtest.c
        src/lzf.h
        src/lzf_c.c
        src/lzf_d.c
        src/latency.c

        src/setproctitle.c
        src/zipmap.c
        src/ziplist.c
        src/zmalloc.c #内存申请释放封装
        src/slowlog.c
        src/hyperloglog.c
        src/bitops.c
        src/sentinel.c

        src/bio.c #后台文件io
        src/anet.c #socket操作封装
        src/ae.c #ae事件驱动库

        src/scripting.c
        src/rio.c
        src/release.c
        src/dict.c
        src/crc16.c
        src/crc64.c
        )

LINK_DIRECTORIES(/usr/local/lib deps/lua/src deps/hiredis)

add_executable(redis_server ${SOURCE_FILES} ${cpp_lua} ${cpp_hiredis} ${geohash_int})

target_link_libraries(redis_server lua hiredis m pthread c dl)


project(redis_test)
set(CMAKE_CXX_STANDARD c++11)

add_executable(redis_test test.c src/pqsort.c)