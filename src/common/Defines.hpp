#ifndef DEFINES_H
#define DEFINES_H

#define VERSION 0x010B

#define MTU 1500
#define STD_BUFFERSIZE 1600
//ECM
#define TTLIn 10
#define TTLOut 10
#define TTLChannel 10
#define CHANNEL_ID_MESCLANDO -1

#define SECONDS 1000000000

//Message Header Sizes
#define MESSAGE_HEADER_SIZE                      6
#define MESSAGE_CHANNEL_HEADER_SIZE             22  // aumento de 1 para o valor do booleano serverAux
#define MESSAGE_REQUEST_HEADER_SIZE             18
#define MESSAGE_ERROR_HEADER_SIZE                8
#define MESSAGE_STATE_CHANNEL_SIZE               8
#define MESSAGE_SERVERAUX_HEADER_SIZE            8
#define MESSAGE_PEERLIST_HEADER_SIZE            10
#define MESSAGE_PEERLIST_SHARE_HEADER_SIZE      38
#define MESSAGE_PEERLIST_LOG_HEADER_SIZE        18
#define MESSAGE_PING_HEADER_SIZE                14
#define MESSAGE_PING_BOOT_HEADER_SIZE           22
#define MESSAGE_PING_BOOT_PERF_HEADER_SIZE      98  // aumento de 2 In e 2 Out  valor antigo = 94
#define MESSAGE_DATA_HEADER_SIZE                22

//Client Operation Modes
enum PeerModes
{
    MODE_CLIENT            = 0x00,          // Modo Client
    MODE_SERVER            = 0x01,          // Modo Server
    MODE_FREERIDER_GOOD    = 0x02,          // Modo Freerider Good
    MODE_FULLCHUNKMAP      = 0x03,          // Modo Anunciando FULL ChunkMap
    MODE_SUPERNODE         = 0x04,          // Modo Supernode
    //MODE_AUXILIAR_SERVER   = 0x05,          // não usado
};

//CHANNEL MESSAGES FLAGS
enum ChannelFlags
{
    CHANNEL_CREATE      = 0x00,
    CHANNEL_CONNECT     = 0x01,
    CHANGE_STATE        = 0X02,
    //CONFIRM_STATE       = 0X03,   //ainda não usado
};

enum ChannelModes
{
	NULL_MODE               	=0x00,          // Usado para desconsiderar esse campo em mensagesn ao Channel
	MODE_NORMAL             	=0x01,          // Modo Normal
	MODE_FLASH_CROWD        	=0x02,          // Modo que ativa os sub-canais
	MODE_FLASH_CROWD_MESCLAR	=0X03,
};

//Operation Codes
enum Opcodes
{
    OPCODE_CHANNEL      = 0x00,
    OPCODE_PEERLIST     = 0x01,
    OPCODE_PING         = 0x02,
    OPCODE_REQUEST      = 0x03,
    OPCODE_DATA         = 0x04,
    OPCODE_ERROR        = 0x05,
    OPCODE_SERVERAUX    = 0x06,
};


//PING MESSAGES FLAGS
enum PingTypes
{
    PING_BASE           = 0x00,     // PING BASE
    PING_BOOT           = 0x01,     // PING TO BOOTSTRAP
    PING_BOOT_PERF      = 0x02,     // PING TO BOOTSTRAP WITH PERFORMANCE INFORMATION
    PING_PART_PERF      = 0x03,     // PING TO PARTNER WITH PERFORMANCE INFORMATION
    PING_PART_CHUNKMAP  = 0x04,     // PING TO PARTNER WITH CHUNK MAP
    PING_LIVE_OUT       = 0x05,     // PING TO PARTNER INFORMING THAT LIVE PEER-OUT
};

//PEERLIST MESSAGES FLAGS
enum PeerlistTypes
{
    PEERLIST_BASE          = 0x00,     // PEERLIST BASE
    PEERLIST_SHARE         = 0x01,     // PEERLIST TO SHARE PARTNERS
    PEERLIST_LOG           = 0x02      // PEERLIST TO LOG
};

enum ServerAuxTypes
{
	NO_SERVER_AUX           = 0X00,    // PEERMANAGER NORMAL
	SERVER_AUX_ACTIVE       = 0x01,    // PEERMANAGER SERVER AUX
	SERVER_AUX_MESCLAR      = 0x02     // PEERMANAGER MESCLANDO REDE
};

//ERROR MESSAGES FLAGS
enum ErrorTypes
{
    ERROR_NONE                      = 0x00,
    ERROR_INVALID_CLIENT_VERSION    = 0x01,
    ERROR_CHANNEL_CANT_BE_CREATED   = 0x02,
    ERROR_CHANNEL_UNAVAILABLE       = 0x03,
    ERROR_CHUNK_UNAVAILABLE         = 0x04,
    ERROR_UPLOAD_LIMIT_EXCEEDED     = 0x05,
    ERROR_NO_PARTNERSHIP            = 0x06,
    ERROR_CHANNEL_STATE_NULL        = 0X07,
};

#endif // DEFINES_H
