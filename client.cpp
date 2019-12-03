#include"client.h"
#include<sys/msg.h>
namespace ASGNMENT {
    void MessageSender::setFilePath(std::string filePath)
    {
        m_sFilePath = filePath;
        if(inputFileStream.is_open())
        {
            inputFileStream.close();
        }
        inputFileStream.open(m_sFilePath.c_str(),std::ifstream::in);
    }

    std::string MessageSender::getFilePath()
    {
        return m_sFilePath;
    }

    std::string MessageSender::readNextInput()
    {
        std::string linr;
        inputFileStream>>linr;
        return linr;
    }

    void MessageSender::createMessage(const std::string& msgId, const std::string& msgName)
    {
        AMessage message;
        message.m_message_id = std::stoi(msgId);
        message.m_message_name = msgName;
    }

    int MessageSender::createMessageQueue()
    {
        key_t queueKey = ftok(ASGNMENT::inputFilePath.c_str(),1);
        m_iQueueId = msgget(queueKey,IPC_CREAT);
        return m_iQueueId;
    }

    int MessageSender::sendMessageOnQueue(const AMessage& msg)
    {
        int message_size = 4;// sizeof(AMessage);
        return msgsnd(m_iQueueId,&msg,message_size,IPC_NOWAIT);
    }

}
