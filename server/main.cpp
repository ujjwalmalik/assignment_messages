#include "tst_server.h"
#include"../MessageReceiver.h"
#include <gtest/gtest.h>
#define UNIT_TESTING 0

void serverSideDataReceive(std::string inputFilepath, std::string outputFilepath)
{
    ASGNMENT::MessageReceiver dataReceiver;
    std::string fileP(inputFilepath);
    dataReceiver.setInputFilePath(fileP);

    std::string outfileP(outputFilepath);
    dataReceiver.setOutputFilePath(outfileP);

    int queueId = dataReceiver.createMessageQueue(inputFilepath);

//    ASGNMENT::QMessage m = dataReceiver.receiveQMessageOnQueue(queueId);
//    dataReceiver.writeMessageToFile(m);

    std::vector<ASGNMENT::QMessage> messages = dataReceiver.receiveAllQMessageOnQueue( queueId);
    dataReceiver.writeMessagesToFile(messages);

    return;
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

            serverSideDataReceive(inputFilePath,outputFilePath);
        }
    }



#endif
    return 0;
}


