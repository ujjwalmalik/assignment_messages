#ifndef _SERVER_H
#define _SERVER_H
#include <fstream>
#include"../common.h"
#include<vector>
#define ASGNMENT_UNUSED_VAR(x) (void)x;
namespace  ASGNMENT {

    class MessageReceiver
    {
    public:
        void setInputFilePath(std::string filePath);
        void setOutputFilePath(std::string filePath);
        std::string getFilePath();
        std::string readNextInputFromFile();

        void    createMessage( const std::__cxx11::string  &msgId, const std::__cxx11::string &msgName);
        int     createMessageQueue(std::string inputFilePath);

        QMessage receiveQMessageOnQueue();
        QMessage convertAMessageToQMessage(AMessage a)
        {
            QMessage m;
            m.id            = a.m_message_id;
            m.message_id    = a.m_message_id;
            if(a.m_message_name.length()+1 < MAX_STRING_LEN)
            {
                strncpy(m.name,a.m_message_name.c_str(),a.m_message_name.length());
                m.name[a.m_message_name.length()+1] = '\0';
            }
            else
            {
                strncpy(m.name,"Default",strlen("Default"));
            }
            return m;
        }

        QMessage convertQMessageToAMessage(AMessage a)
        {
            QMessage m;
            m.id            = a.m_message_id;
            m.message_id    = a.m_message_id;
            if(a.m_message_name.length()+1 < MAX_STRING_LEN)
            {
                strncpy(m.name,a.m_message_name.c_str(),a.m_message_name.length());
                m.name[a.m_message_name.length()+1] = '\0';
            }
            else
            {
                strncpy(m.name,"Default",strlen("Default"));
            }
            return m;
        }

        bool writeMessageToFile(const QMessage &msg);
        std::vector<QMessage> receiveAllQMessageOnQueue(int queueID);
        bool writeMessagesToFile(const std::vector<ASGNMENT::QMessage> &messages);
    protected:
        void sendAckMessagesToQueue(int queueId);
    private:
        std::string     m_sInputFilePath;
        std::string     m_sOutputFilePath;
        std::ifstream   m_inputFileStream;
        std::ofstream   m_outputFileStream;

        int m_iQueueId;

    };
}


#endif // _SERVER_H
