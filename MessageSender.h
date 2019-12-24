#ifndef _CLIENT_H
#define _CLIENT_H
#include <fstream>
#include "../common.h"
#define ASGNMENT_UNUSED_VAR(x) (void)x;
namespace  ASGNMENT {

    class MessageSender
    {
    public:
        void setFilePath(std::string filePath);
        std::string getFilePath();
        bool endOfFile()
        {
            return m_inputFileStream.eof();
        }
        std::string readNextInputFromFile();

        void    createMessage( const std::__cxx11::string  &msgId, const std::__cxx11::string &msgName);
        int     createMessageQueue();

        int sendAMessageOnQueue(const AMessage &msg);
        QMessage convertAMessageToQMessage(AMessage a)
        {
            QMessage m;
            m.id            = 1;
            m.message_id    = a.m_message_id;
            if(a.m_message_name.length()+1 < MAX_STRING_LEN)
            {
                int p =  a.m_message_name.length();
                strncpy(m.name,a.m_message_name.c_str(),a.m_message_name.length());
                m.name[a.m_message_name.length()] = '\0';
            }
            else
            {
                strncpy(m.name,"Default",strlen("Default"));
            }
            return m;
        }
    private:
        std::string m_sFilePath;
        std::ifstream m_inputFileStream;

        int m_iQueueId;

    };
}


#endif // _CLIENT_H
