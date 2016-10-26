cmake_minimum_required(VERSION 3.5)
project(LMutex)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")

set(SOURCE_FILES main.cpp Events.h Handler.cpp Handler.h Listener.cpp Listener.h LMutex.cpp LMutex.h Message.h MessageBuilder.cpp MessageBuilder.h NetManager.cpp NetManager.h Packer.cpp Packer.h SafeQueue.h SafeQueue.cpp Sender.cpp Sender.h Worker.cpp Worker.h EventsQueue.cpp EventsQueue.h ReleaseHandler.cpp ReleaseHandler.h ReplyHandler.cpp ReplyHandler.h RequestHandler.cpp RequestHandler.h UserLockHandler.cpp UserLockHandler.h Node.h Configuration.cpp Configuration.h StressWorker.cpp StressWorker.h UserWorker.cpp UserWorker.h Logger.cpp Logger.h Events.cpp)
add_executable(LMutex ${SOURCE_FILES})