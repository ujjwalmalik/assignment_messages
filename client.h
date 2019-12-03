#ifndef _CLIENT_H
#define _CLIENT_H
#include <fstream>
#include"common.h"
#define ASGNMENT_UNUSED_VAR(x) (void)x;
namespace  ASGNMENT {

    class MessageSender
    {
    public:
        void setFilePath(std::string filePath);
        std::string getFilePath();
        std::string readNextInput();

        void    createMessage( const std::__cxx11::string  &msgId, const std::__cxx11::string &msgName);
        int     createMessageQueue();

        int sendMessageOnQueue(const AMessage &msg);
    private:
        std::string m_sFilePath;
        std::ifstream inputFileStream;

        int m_iQueueId;

    };
}


#endif // _CLIENT_H
