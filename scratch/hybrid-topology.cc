#include "ns3/core-module.h"
#include "ns3/network-module.h"
#include "ns3/internet-module.h"
#include "ns3/point-to-point-module.h"
#include "ns3/csma-module.h"
#include "ns3/netanim-module.h"

using namespace ns3;

int main ()
{
    NodeContainer nodes;
    nodes.Create (25);

    InternetStackHelper internet;
    internet.Install (nodes);

    PointToPointHelper p2p;
    p2p.SetDeviceAttribute ("DataRate", StringValue ("10Mbps"));
    p2p.SetChannelAttribute ("Delay", StringValue ("2ms"));

    CsmaHelper csma;
    csma.SetChannelAttribute ("DataRate", StringValue ("100Mbps"));
    csma.SetChannelAttribute ("Delay", TimeValue (NanoSeconds (6560)));

    // ================= BUS (1–5) =================
    NodeContainer bus;
    bus.Add (nodes.Get (0));
    for (int i = 1; i <= 5; i++)
        bus.Add (nodes.Get (i));
    csma.Install (bus);

    // ================= STAR (6–10) =================
    for (int i = 6; i <= 10; i++)
        p2p.Install (nodes.Get (0), nodes.Get (i));

    // ================= RING (11–15) =================
    for (int i = 11; i < 15; i++)
        p2p.Install (nodes.Get (i), nodes.Get (i + 1));
    p2p.Install (nodes.Get (15), nodes.Get (11));
    p2p.Install (nodes.Get (0), nodes.Get (11));   // connect ring to backbone

    // ================= TREE (16–20) =================
    p2p.Install (nodes.Get (0), nodes.Get (16));
    p2p.Install (nodes.Get (16), nodes.Get (17));
    p2p.Install (nodes.Get (16), nodes.Get (18));
    p2p.Install (nodes.Get (17), nodes.Get (19));
    p2p.Install (nodes.Get (17), nodes.Get (20));

    // ================= MESH (21–24) =================
    for (int i = 21; i <= 24; i++)
        p2p.Install (nodes.Get (0), nodes.Get (i));

    p2p.Install (nodes.Get (21), nodes.Get (22));
    p2p.Install (nodes.Get (22), nodes.Get (23));
    p2p.Install (nodes.Get (23), nodes.Get (24));
    p2p.Install (nodes.Get (21), nodes.Get (24));

    // ================= NetAnim =================
    AnimationInterface anim ("hybrid25.xml");

    Simulator::Run ();
    Simulator::Destroy ();
    return 0;
}