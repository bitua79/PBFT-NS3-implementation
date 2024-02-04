#include "ns3/core-module.h" 
#include "network-helper.h"
#include "ns3/string.h"
#include "ns3/inet-socket-address.h"
#include "ns3/names.h"
#include "ns3/network-module.h"
#include "ns3/internet-module.h"
#include "ns3/applications-module.h"


namespace ns3 {
    NetworkHelper::NetworkHelper(uint32_t totalNoNodes) {
        m_factory.SetTypeId ("ns3::NodeApp");
        m_nodeNo = totalNoNodes;
    }
    
    ApplicationContainer
    NetworkHelper::Install (NodeContainer c)
    { 
        std::srand(static_cast<unsigned int>(time(0)));
        ApplicationContainer apps;
        int j = 0;

        int leader_id = (rand() % m_nodeNo);
        
        for (NodeContainer::Iterator i = c.Begin (); i != c.End (); i++)
        {
            Ptr<NodeApp> app = m_factory.Create<NodeApp> ();
            uint32_t nodeId = (*i)->GetId(); 
            app->m_id = nodeId;
            app->N = m_nodeNo;

            if (j == leader_id) {
                app->is_leader = 1;
            } else {
                app->is_leader = 0;
            }

            app->leader_id= leader_id;
            app->view_number = 1;
            app->client_id = -1;
            app->sec_num = 0;
            app->m_peersAddresses = m_nodesConnectionsIps[nodeId];
            (*i)->AddApplication (app);
            apps.Add (app);
            j++;
        }
        return apps;
    }
}