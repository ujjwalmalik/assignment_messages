#ifndef COMMON_H
#define COMMON_H
#include<iostream>
#include<string.h>
#include<vector>
namespace ASGNMENT {


    const int DATA_MESSAGE_ID   =   1;
    const int ACK_MESSAGE_ID    =   45;
//    std::string inputFilePath = "/home/ujjwal/assignment/assignment_messages/input.txt";
//    std::string outputFilePath = "/home/ujjwal/assignment/assignment_messages/output.txt";
    const int MAX_STRING_LEN = 60;
    struct AMessage
    {
        int         m_message_id;
        std::string m_message_name;
        AMessage(std::string id, std::string text)
        {
            try
            {
                m_message_id    = std::stoi(id);
            }
            catch(...)
            {
                m_message_id = -1;
            }

            m_message_name  = text;
        }
        AMessage():m_message_id(-1)
                            ,m_message_name("")
        {

        }
    };
    struct QMessage
    {
        long        id;
        int         message_id;
        char        name[MAX_STRING_LEN];
    };

    struct AckMessage
    {
        long        id;
        int         ack_id;
        char        name[1];
    };
}

#endif // COMMON_H
