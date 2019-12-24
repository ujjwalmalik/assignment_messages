#include"../MessageSender.h"
#include<sys/msg.h>
 #include <errno.h>
namespace ASGNMENT {
    void MessageSender::setFilePath(std::string filePath)
    {
        m_sFilePath = filePath;
        if(m_inputFileStream.is_open())
        {
            m_inputFileStream.close();
        }
        m_inputFileStream.open(m_sFilePath.c_str(),std::ifstream::in);
    }

    std::string MessageSender::getFilePath()
    {
        return m_sFilePath;
    }

    std::string MessageSender::readNextInputFromFile()
    {
        std::string linr;
        m_inputFileStream>>linr;
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
        m_iQueueId = msgget(queueKey,IPC_CREAT|0666);
        return m_iQueueId;
    }

    int MessageSender::sendAMessageOnQueue(const AMessage& msg)
    {
        QMessage m;
        m = convertAMessageToQMessage(msg);
        int stats = msgsnd(m_iQueueId,&m,sizeof(m),IPC_NOWAIT);
        return stats;
    }
}
