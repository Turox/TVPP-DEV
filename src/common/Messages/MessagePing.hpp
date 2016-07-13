#ifndef MESSAGE_PING_H
#define MESSAGE_PING_H

#include "Message.hpp" 
#include "../ChunkUniqueID.hpp"

class MessagePing : public Message
{
    public:
        MessagePing() : Message() {};
        MessagePing(Message* message) : Message(message->GetFirstByte()) {};
        MessagePing(PingTypes pingType, uint16_t bodySize, PeerModes mode, ChunkUniqueID chunkuid, uint16_t sizePeerListOut);
        vector<int> GetHeaderValuesDataVector(PingTypes pingType, PeerModes mode, ChunkUniqueID chunkuid, uint16_t sizePeerListOut);
        virtual vector<uint8_t> GetHeaderValuesSizeVector();
};

#endif // MESSAGE_PING_H    
