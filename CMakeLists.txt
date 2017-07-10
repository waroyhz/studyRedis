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
        src/server.c
        src/redis-check-rdb.c
        src/geo.c
        deps/geohash-int/geohash.c
        deps/geohash-int/geohash_helper.c

        src/config.c
        src/object.c
        src/debug.c
        src/syncio.c
        src/rand.c

        src/util.c
        src/aof.c
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
        src/zmalloc.c
        src/slowlog.c
        src/hyperloglog.c
        src/bitops.c
        src/sentinel.c

        src/bio.c
        src/anet.c
        src/ae.c

        src/scripting.c
        src/rio.c
        src/release.c
        src/dict.c
        src/crc16.c
        src/crc64.c
        )

#aux_source_directory(deps/lua/src cpp_lua)
#aux_source_directory(deps/hiredis cpp_hiredis)
#aux_source_directory(deps/geohash-int geohash_int)

LINK_DIRECTORIES(/usr/local/lib deps/lua/src deps/hiredis)

#execute_process(
#        COMMAND "cd deps/lua/src && make"
#        COMMAND "cd deps/hiredis && make"
#        COMMAND "cd deps/geohash-int && make"
#    )

add_executable(redis_server ${SOURCE_FILES} ${cpp_lua} ${cpp_hiredis} ${geohash_int})

target_link_libraries(redis_server lua hiredis m pthread c dl)