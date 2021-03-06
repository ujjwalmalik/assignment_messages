#include"../MessageSender.h"
#include<sys/msg.h>
#include <errno.h>
using namespace ASGNMENT;


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

int MessageSender::createMessageQueue(std::string filePathForQueueId)
{
    key_t queueKey = ftok(filePathForQueueId.c_str(),1);
    int iQueueId = msgget(queueKey,IPC_CREAT|0666);
    return iQueueId;
}

int MessageSender::sendAMessageOnQueue(int queueId, const AMessage& msg)
{
    QMessage m;
    m = convertAMessageToQMessage(msg);
    int stats = msgsnd(queueId,&m,sizeof(m),IPC_NOWAIT);
    return stats;
}

    //    std::vector<AckMessage> MessageSender::receiveAllAckMessageOnQueue()
    //    {
    //        std::vector<AckMessage> messages;
    //        AckMessage m;
    //        bool bIsQueueEmpty = false;
    //        ssize_t size = 0;
    //        int cnt = 0;
    //        do
    //        {
    //            ++cnt;
    //            size = msgrcv(m_iAckQueueId,&m,sizeof(AckMessage),1,IPC_NOWAIT);
    //            if(size !=-1)
    //            {
    //                messages.push_back(m);
    //            }
    //            else // size == -1
    //            {
    //                int errorCode = errno;
    //                if(ENOMSG == errorCode)
    //                {
    //                    bIsQueueEmpty = true;
    //                }
    //            }
    //        }
    //        while(!bIsQueueEmpty);

    //        return messages;
    //    }

