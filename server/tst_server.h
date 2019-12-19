#pragma once

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include "server.h"

using namespace testing;

TEST(InvalidServerInputFile, Suite)
{

}

TEST(InvalidServerInputFilePath, Suite)
{
    ASGNMENT::MessageSender sender;
    std::string fileP(ASGNMENT::inputFilePath);
    sender.setInputFilePath(fileP);
    ASSERT_EQ(fileP,sender.getFilePath());
}


TEST(ReadServerInputFileFirstLine, Suite)
{
    ASGNMENT::MessageSender sender;
    std::string fileP(ASGNMENT::inputFilePath);
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
    ASGNMENT::MessageSender sender;
    int mqIdendtifier = sender.createMessageQueue();
    std::cout<<mqIdendtifier;
    ASSERT_NE(mqIdendtifier,-1);
}

TEST(SendMessageOnQueue, Suite)
{
    ASGNMENT::MessageSender sender;
    int mqIdendtifier = sender.createMessageQueue();
    if(mqIdendtifier >0)
    {
        ASGNMENT::AMessage message;
        message.m_message_id = 1;
        message.m_message_name = "a";
        std::cout<<"\nsizeof message =   "<<sizeof(message)<<std::endl;

        sender.receiveQMessageOnQueue();

    }
}
