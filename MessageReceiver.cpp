#include<sys/msg.h>
#include <errno.h>
#include<fstream>
#include"MessageReceiver.h"
namespace ASGNMENT {
    void MessageReceiver::setInputFilePath(std::string filePath)
    {
        m_sInputFilePath = filePath;
        if(m_inputFileStream.is_open())
        {
            m_inputFileStream.close();
        }
        m_inputFileStream.open(m_sInputFilePath.c_str(),std::ifstream::in);
    }

    void MessageReceiver::setOutputFilePath(std::string filePath)
    {
        m_sOutputFilePath = filePath;
        if(m_outputFileStream.is_open())
        {
            m_outputFileStream.close();
        }
        m_outputFileStream.open(m_sOutputFilePath.c_str(),std::ofstream::out);
    }

    std::string MessageReceiver::getFilePath()
    {
        return m_sInputFilePath;
    }

    std::string MessageReceiver::readNextInputFromFile()
    {
        std::string linr;
        m_inputFileStream>>linr;
        return linr;
    }

    void MessageReceiver::createMessage(const std::string& msgId, const std::string& msgName)
    {
        AMessage message;
        message.m_message_id = std::stoi(msgId);
        message.m_message_name = msgName;
    }

    int MessageReceiver::createMessageQueue()
    {
        key_t queueKey = ftok(ASGNMENT::inputFilePath.c_str(),1);
        m_iQueueId = msgget(queueKey,IPC_CREAT|0666);
        return m_iQueueId;
    }
    std::vector<QMessage> MessageReceiver::receiveAllQMessageOnQueue()
    {
        std::vector<QMessage> messages;
        QMessage m;
        bool bIsQueueEmpty = false;
        ssize_t size = 0;
        int cnt = 0;
        do
        {
            if(cnt == 19)
            {
                int a = 10;
            }
            ++cnt;
            size = msgrcv(m_iQueueId,&m,sizeof(QMessage),1,IPC_NOWAIT);
            if(size !=-1)
            {
                messages.push_back(m);
            }
            else // size == -1
            {
                int errorCode = errno;
                if(ENOMSG == errorCode)
                {
                    bIsQueueEmpty = true;
                }
            }
        }
        while(!bIsQueueEmpty);

        return messages;
    }
    QMessage MessageReceiver::receiveQMessageOnQueue()
    {
        QMessage m;
        ssize_t size = msgrcv(m_iQueueId,&m,sizeof(QMessage),1,IPC_NOWAIT);
        if(size !=-1)
        {
            std::cout<<m.id<<std::endl;
            std::cout<<m.message_id<<std::endl;
            std::cout<<m.name<<std::endl;

            std::cout<<"\nmsgrcv returned = "<<size<<"\n";
            return m;
        }
        else
        {
            //check if value of errno is ENOMSG
        }
    }

    bool MessageReceiver::writeMessagesToFile(const std::vector<ASGNMENT::QMessage>& messages)
    {
        for(std::vector<ASGNMENT::QMessage>::const_iterator it = messages.begin();it!=messages.end();++it)
        {
            const QMessage m = *it;
            writeMessageToFile(m);
        }
    }

    bool MessageReceiver::writeMessageToFile(const QMessage& msg)
    {
        std::string s = std::to_string(msg.message_id);
        m_outputFileStream.write(s.c_str(),s.length());
        m_outputFileStream.write("\t",1);
        int a = strlen(msg.name);
        m_outputFileStream.write(msg.name,strlen(msg.name));
        m_outputFileStream.write("\n",1);
        m_outputFileStream.flush();
    }
}
