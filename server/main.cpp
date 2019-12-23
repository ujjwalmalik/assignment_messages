#include "tst_server.h"
#include"server.h"
#include <gtest/gtest.h>
#define UNIT_TESTING 0

int serverSide()
{
    ASGNMENT::MessageSender sender;
    std::string fileP(ASGNMENT::inputFilePath);
    sender.setInputFilePath(fileP);

    std::string outfileP(ASGNMENT::outputFilePath);
    sender.setOutputFilePath(outfileP);

    int queueId = sender.createMessageQueue();

//    ASGNMENT::AMessage a(first,second);
    ASGNMENT::QMessage m = sender.receiveQMessageOnQueue();
    sender.writeMessageToFile(m);

    std::vector<ASGNMENT::QMessage> messages = sender.receiveAllQMessageOnQueue();
    sender.writeMessagesToFile(messages);
    return 0;
}

int main(int argc, char *argv[])
{
#if(UNIT_TESTING == 1)
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
#else
int status = serverSide();

#endif
    return 0;
}


