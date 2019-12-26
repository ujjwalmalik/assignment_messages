#pragma once

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include "../MessageReceiver.h"

using namespace testing;
std::string inputFilePath = "/home/ujjwal/assignment/assignment_messages/input.txt";
//std::string outputFilePath = "/home/ujjwal/assignment/assignment_messages/output.txt";

TEST(InvalidServerInputFile, Suite)
{

}

TEST(InvalidServerInputFilePath, Suite)
{
    ASGNMENT::MessageReceiver sender;
    std::string fileP(inputFilePath);
    sender.setInputFilePath(fileP);
    ASSERT_EQ(fileP,sender.getFilePath());
}


TEST(ReadServerInputFileFirstLine, Suite)
{
    ASGNMENT::MessageReceiver sender;
    std::string fileP(inputFilePath);
    std::string inputFirstLine =  "1234";
    std::string inputSecondLine =  "Hello";
    sender.setInputFilePath(fileP);
    std::string first   = sender.readNextInputFromFile();
    std::string second  = sender.readNextInputFromFile();
    ASSERT_EQ(first,inputFirstLine);
    ASSERT_EQ(second,inputSecondLine);
}

TEST(CreateMessageQueue, Suite)
{
    ASGNMENT::MessageReceiver sender;
    int mqIdendtifier = sender.createMessageQueue(inputFilePath);
    std::cout<<mqIdendtifier;
    ASSERT_NE(mqIdendtifier,-1);
}

TEST(SendMessageOnQueue, Suite)
{
    ASGNMENT::MessageReceiver sender;
    int mqIdendtifier = sender.createMessageQueue(inputFilePath);
    if(mqIdendtifier >0)
    {
        ASGNMENT::AMessage message;
        message.m_message_id = 1;
        message.m_message_name = "a";
        std::cout<<"\nsizeof message =   "<<sizeof(message)<<std::endl;

        sender.receiveQMessageOnQueue();

    }
}
