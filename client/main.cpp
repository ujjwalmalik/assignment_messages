#include "tst_client.h"
#include"../MessageSender.h"
#include <gtest/gtest.h>
#define UNIT_TESTING 0

void clientSideDataSend()
{
    ASGNMENT::MessageSender dataSender;
    std::string fileP(ASGNMENT::inputFilePath);
    dataSender.setFilePath(fileP);
    dataSender.createMessageQueue();

    while(!dataSender.endOfFile())
    {
        std::string first   = dataSender.readNextInputFromFile();
        std::string second  = dataSender.readNextInputFromFile();
        if((!first.length() == 0) && (!second.length() == 0))
        {
            ASGNMENT::AMessage a(first,second);
            dataSender.sendAMessageOnQueue(a);
        }
    }

    return;
}

void clientSideReceiveAck()
{

}

int main(int argc, char *argv[])
{

#if(UNIT_TESTING == 1)
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
#else
clientSideDataSend();
clientSideReceiveAck();

#endif
    return 0;
}


