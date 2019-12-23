#include "tst_client.h"
#include"client.h"
#include <gtest/gtest.h>
#define UNIT_TESTING 0

int clientSide()
{
    ASGNMENT::MessageSender sender;
    std::string fileP(ASGNMENT::inputFilePath);
    sender.setFilePath(fileP);
    sender.createMessageQueue();

    while(!sender.endOfFile())
    {
        std::string first   = sender.readNextInputFromFile();
        std::string second  = sender.readNextInputFromFile();
        if((!first.length() == 0) && (!second.length() == 0))
        {
            ASGNMENT::AMessage a(first,second);
            sender.sendAMessageOnQueue(a);
        }
    }
    return 0;
}

int main(int argc, char *argv[])
{
#if(UNIT_TESTING == 1)
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
#else
int status = clientSide();
int a = 100;
#endif
    return 0;
}


