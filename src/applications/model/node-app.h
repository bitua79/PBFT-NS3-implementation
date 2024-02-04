#ifndef NODE_APP_H
#define NODE_APP_H

#include <algorithm>
#include "ns3/application.h"
#include "ns3/event-id.h"
#include "ns3/ptr.h"
#include "ns3/traced-callback.h"
#include "ns3/address.h"
#include "ns3/boolean.h"
#include <map>

namespace ns3 {

class Address;
class Socket;
class Packet;

enum PBFTPhase {
    CLIENT_CHANGE,  // 0
    NEW_ROUND,      // 1
    REQUEST,        // 2
    PRE_PREPARED,   // 3
    PREPARED,       // 4
    COMMITTED,      // 5
    REPLY,          // 6
    VIEW_CHANGE     // 7
};

struct Transaction {
    int view;
    int value;
    int prepare_vote;
    int commit_vote;
};

class NodeApp : public Application
{
  public:
    static TypeId GetTypeId (void);

    NodeApp (void);

    virtual ~NodeApp (void);

    uint32_t        m_id;                               // node id
    Ptr<Socket>     m_socket;                           // Listening socket
    std::map<Ipv4Address, Ptr<Socket>>      m_peersSockets;            // Socket list of neighbor nodes
    std::map<Address, std::string>          m_bufferedData;            // map holding the buffered data from previous handleRead events
    
    Address         m_local;                            // Address of this node
    std::vector<Ipv4Address>  m_peersAddresses;         // Neighbor list

    std::vector<char> ledger;
    
    int             N;                                  // Total number of nodes
    int             is_leader;                          // Are you a leader?
    int             sec_num;                            // The transaction sequence number 
    int             view_number;                        // View node id

    int             leader_id;                          
    int             client_id;

    static const int arraySize = 10;
    Transaction transactions[arraySize];                // Declaration of the array

    virtual void StartApplication (void);
    virtual void StopApplication (void); 

    void HandleRead (Ptr<Socket> socket);

    std::string getPacketContent(Ptr<Packet> packet, Address from); 

    void SendTX(uint8_t data[], int num);

    void SendTXWithDelay(uint8_t data[], int size, double delay);

    void initiateRound(void);

    void changeView(void);

    void sendStringMessage(std::string data);

    void printInformation();
};
}
#endif