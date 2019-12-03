#ifndef COMMON_H
#define COMMON_H
#include<iostream>
namespace ASGNMENT {
    const std::string inputFilePath = "/home/ujjwal/assignment/aa.txt";
    const int MAX_STRING_LEN = 60;
    struct AMessage
    {
        int         m_message_id;
        std::string m_message_name;
    };

    struct QMessage
    {
        long        id;
        int         message_id;
        char        name[MAX_STRING_LEN];
    };

    convertAMessageToQMessage(AMessage a, QMessage q)
    {

    }
}

#endif // COMMON_H
