//
// Created by alex on 26.10.16.
//

#include "Events.h"

std::uint8_t Events::Reply = 0;
std::uint8_t Events::Release = 1;
std::uint8_t Events::Request = 2;
std::uint8_t Events::UserLock = 3;
std::uint8_t Events::Terminate = 4;
std::uint8_t Events::TerminateReply = 5;
std::uint8_t Events::FinishNetwork = 6;
std::uint8_t Events::FinishSender = 7;