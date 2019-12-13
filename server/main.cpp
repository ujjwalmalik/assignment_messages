#include "tst_server.h"
#include"server.h"
#include <gtest/gtest.h>
#define UNIT_TESTING 0

int serverSide()
{
    ASGNMENT::MessageSender sender;
    std::string fileP(ASGNMENT::inputFilePath);
    sender.setFilePath(fileP);
    sender.createMessageQueue();

    std::string first   = sender.readNextInputFromFile();
    std::string second  = sender.readNextInputFromFile();
    ASGNMENT::AMessage a(first,second);
    sender.receiveQMessageOnQueue();
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


