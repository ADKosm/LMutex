cmake_minimum_required(VERSION 3.5)
project(LMutex)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")

set(SOURCE_FILES src/Events.h src/Handler.cpp src/Handler.h src/Listener.cpp src/Listener.h src/LMutex.cpp src/LMutex.h src/Message.h src/MessageBuilder.cpp src/MessageBuilder.h src/NetManager.cpp src/NetManager.h src/Packer.cpp src/Packer.h src/SafeQueue.h src/SafeQueue.cpp src/Sender.cpp src/Sender.h src/Worker.cpp src/Worker.h src/EventsQueue.cpp src/EventsQueue.h src/ReleaseHandler.cpp src/ReleaseHandler.h src/ReplyHandler.cpp src/ReplyHandler.h src/RequestHandler.cpp src/RequestHandler.h src/UserLockHandler.cpp src/UserLockHandler.h src/Node.h src/Configuration.cpp src/Configuration.h src/StressWorker.cpp src/StressWorker.h src/UserWorker.cpp src/UserWorker.h src/Logger.cpp src/Logger.h src/Events.cpp src/TerminateHandler.cpp src/TerminateHandler.h src/TerminateReplyHandler.cpp src/TerminateReplyHandler.h src/ReplyComparator.h)
add_executable(LMutex src/main.cpp ${SOURCE_FILES})
add_executable(runTests tests/runTests.cpp ${SOURCE_FILES} tests/TestNetManager.cpp tests/TestNetManager.h tests/TestConfiguration.cpp tests/TestConfiguration.h tests/TestLogger.cpp tests/TestLogger.h)