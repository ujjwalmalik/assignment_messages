#include "tst_server.h"
#include"../MessageReceiver.h"
#include <gtest/gtest.h>
#define UNIT_TESTING 0

void serverSideDataReceive()
{
    ASGNMENT::MessageReceiver dataReceiver;
    std::string fileP(ASGNMENT::inputFilePath);
    dataReceiver.setInputFilePath(fileP);

    std::string outfileP(ASGNMENT::outputFilePath);
    dataReceiver.setOutputFilePath(outfileP);

    int queueId = dataReceiver.createMessageQueue();

//    ASGNMENT::AMessage a(first,second);
    ASGNMENT::QMessage m = dataReceiver.receiveQMessageOnQueue();
    dataReceiver.writeMessageToFile(m);

    std::vector<ASGNMENT::QMessage> messages = dataReceiver.receiveAllQMessageOnQueue();
    dataReceiver.writeMessagesToFile(messages);
    return;
}

int main(int argc, char *argv[])
{
#if(UNIT_TESTING == 1)
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
#else
    serverSideDataReceive();

#endif
    return 0;
}


