#pragma once

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include "../MessageSender.h"

using namespace testing;
std::string inputFilePath = "/home/ujjwal/assignment/assignment_messages/input.txt";
//std::string outputFilePath = "/home/ujjwal/assignment/assignment_messages/output.txt";

TEST(InvalidClientInputFile, Suite)
{

}

TEST(InvalidClientInputFilePath, Suite)
{

    std::string inputFilePath = "/home/ujjwal/assignment/assignment_messages/input.txt";
    //std::string outputFilePath = "/home/ujjwal/assignment/assignment_messages/output.txt";

    ASGNMENT::MessageSender sender;
    std::string fileP(inputFilePath);
    sender.setFilePath(fileP);
    ASSERT_EQ(fileP,sender.getFilePath());
}


TEST(ReadClientInputFileFirstLine, Suite)
{
    ASGNMENT::MessageSender sender;
    std::string fileP(inputFilePath);
    std::string inputFirstLine =  "1234";
    std::string inputSecondLine =  "Hello";
    sender.setFilePath(fileP);
    std::string first   = sender.readNextInputFromFile();
    std::string second  = sender.readNextInputFromFile();
    ASSERT_EQ(first,inputFirstLine);
    ASSERT_EQ(second,inputSecondLine);
}

TEST(CreateMessageQueue, Suite)
{
    ASGNMENT::MessageSender sender;
    int mqIdendtifier = sender.createMessageQueue(inputFilePath);
    std::cout<<mqIdendtifier;
    ASSERT_NE(mqIdendtifier,-1);
}

TEST(SendMessageOnQueue, Suite)
{
    ASGNMENT::MessageSender sender;
    int mqIdendtifier = sender.createMessageQueue(inputFilePath);

    ASGNMENT::AMessage message;
    message.m_message_id = 1;
    message.m_message_name = "a";
    std::cout<<"\nsizeof message =   "<<sizeof(message)<<std::endl;

    int status = sender.sendAMessageOnQueue(mqIdendtifier,message);
    std::cout<<status;
}
