cmake_minimum_required(VERSION 3.5)
project(TVPP)
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

set(TEMPORIZABLE_SOURCES
        client/Temporizable/LeakyBucket.cpp
        client/Temporizable/Disconnector.cpp
        client/Temporizable/PeerRequester.cpp
        client/Temporizable/Connector.cpp
        )

set(MESSAGE_SOURCES
        common/Messages/Message.cpp
        common/Messages/MessageChannel.cpp
        common/Messages/MessageData.cpp
        common/Messages/MessageError.cpp
        common/Messages/MessagePeerlist.cpp
        common/Messages/MessagePeerlistLog.cpp
        common/Messages/MessagePeerlistShare.cpp
        common/Messages/MessagePing.cpp
        common/Messages/MessagePingBoot.cpp
        common/Messages/MessagePingBootPerf.cpp
        common/Messages/MessageRequest.cpp
        common/Messages/MessageServerSub.cpp
        common/Messages/MessageStateChannel.cpp
        )

set(SCHEDULER_SOURCES
        common/Scheduler/CDFMessageScheduler.cpp
        common/Scheduler/FIFOMessageScheduler.cpp
        common/Scheduler/RandomMessageScheduler.cpp
        common/Scheduler/RRMessageScheduler.cpp
        )

set(COMMON_SOURCES
        ${MESSAGE_SOURCES}
        ${SCHEDULER_SOURCES}
        common/XPConfig.cpp
        common/AddressedMessage.cpp
        common/Sub-Channel-Data.cpp
        common/Channel.cpp
        common/PeerData.cpp
        common/Peer.cpp
        common/UdpBuffer.cpp
        common/ChunkUniqueID.cpp
        common/HeadedBitset.cpp
        common/tcp-server.cpp
        common/tcp-session.cpp
        common/udp.cpp
        )

set(LIBS
        boost_thread
        pthread
        boost_system
        )

find_package(Boost)
if (Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    add_executable(bootstrap
            bootstrap/main.cpp
            bootstrap/bootstrap.cpp
            bootstrap/bootstrap-session.cpp
            bootstrap/bootstrap-tcp-server.cpp
            ${COMMON_SOURCES}
            )
    add_executable(client
            client/main.cpp
            client/client.cpp
            client/Statistics.cpp
            client/MediaBuffer.cpp
            client/PeerManager.cpp
            client/PeerManagerServerAux.cpp
            client/Request.cpp
            client/RequestAttempt.cpp
            client/client-player-session.cpp
            client/client-tcp-server.cpp
            client/client-bootstrap-session.cpp
            ${COMMON_SOURCES}
            ${TEMPORIZABLE_SOURCES}
            )

    add_executable(externalMessage
            externalMessage/main.cpp
            externalMessage/externalMessageTCP.cpp
            ${COMMON_SOURCES}
            )
    target_link_libraries(bootstrap ${LIBS})
    target_link_libraries(client ${LIBS})
    target_link_libraries(externalMessage ${LIBS})
endif ()