#ifndef ETOMIC_CURL_HEADER
#define ETOMIC_CURL_HEADER

#include <stdint.h>
#include <includes/cJSON.h>

#ifdef __cplusplus
extern "C"{
#endif
    
#define ETOMIC_TESTNET
#ifdef ETOMIC_TESTNET
#define ETOMIC_URL "https://ropsten.infura.io/y07GHxUyTgeN2mdfOonu"
#else
#define ETOMIC_URL "https://mainnet.infura.io/y07GHxUyTgeN2mdfOonu"
#endif
    
typedef struct
{
    uint64_t blockNumber;
    uint64_t confirmations;
    char blockHash[75];
    char status[10];
} EthTxReceipt;

typedef struct
{
    char from[50];
    char to[50];
    char input[1000];
    char valueHex[70];
    uint8_t exists;
} EthTxData;

char* sendRawTx(char* rawTx);
char* ethCall(char* to, const char* data);
int64_t getNonce(char* address);
char* getEthBalanceRequest(char* address);
EthTxReceipt getEthTxReceipt(char *txId);
EthTxData getEthTxData(char *txId);
uint64_t getEthBlockNumber();

#ifdef __cplusplus
}
#endif

#endif