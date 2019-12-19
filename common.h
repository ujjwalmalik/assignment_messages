#ifndef COMMON_H
#define COMMON_H
#include<iostream>
#include<string.h>
#include<vector>
namespace ASGNMENT {
    const std::string inputFilePath = "/home/ujjwal/assignment/assignment_messages/input.txt";
    const std::string outputFilePath = "/home/ujjwal/assignment/assignment_messages/output.txt";
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


}

#endif // COMMON_H
