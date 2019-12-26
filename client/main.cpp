#include "tst_client.h"
#include"../MessageSender.h"
//#include"../MessageReceiver.h"
#include <gtest/gtest.h>
#define UNIT_TESTING 0

void clientSideDataSend(std::string inputFilePath)
{
    ASGNMENT::MessageSender dataSender;
    std::string fileP(inputFilePath);
    dataSender.setFilePath(fileP);
    int queueId = dataSender.createMessageQueue(inputFilePath);

    while(!dataSender.endOfFile())
    {
        std::string first   = dataSender.readNextInputFromFile();
        std::string second  = dataSender.readNextInputFromFile();
        if((!first.length() == 0) && (!second.length() == 0))
        {
            ASGNMENT::AMessage a(first,second);
            dataSender.sendAMessageOnQueue(queueId,a);
        }
    }
    return;
}



void clientSideReceiveAck()
{
//    ASGNMENT::MessageReceiver ackReceiver;
//    std::string fileP(ASGNMENT::outputFilePath);
//    ackReceiver.setInputFilePath(fileP);
//    int queueId = ackReceiver.createMessageQueue();
}

int main(int argc, char *argv[])
{

#if(UNIT_TESTING == 1)
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
#else
    if(argc == 2)
    {
        std::string inputData = argv[1];
        std::string fileP(inputData);
        std::ifstream   inputFileStream;
        inputFileStream.open(fileP.c_str(),std::ifstream::in);
        if(inputFileStream.is_open())
        {
            std::string inputFilePath;
            inputFileStream>>inputFilePath;

            std::string outputFilePath;
            inputFileStream>>outputFilePath;

            clientSideDataSend(inputFilePath);
            clientSideReceiveAck();
        }
    }


#endif
    return 0;
}


