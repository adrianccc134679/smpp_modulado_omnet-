

#include "HLR.h"

Define_Module(HLR);

void HLR::initialize()
{
    // TODO - Generated method body
}

void HLR::handleMessage(cMessage *msg)
{
    cGate *arrivalGate = msg ->getArrivalGate();
    if (arrivalGate == gate("in"))
        {

            cMessage *tmsgc = new cMessage("SRIF_SM_confirmation");
     //       cMessage *tmsgn = new cMessage("SRIF_SM_negative");

            send (tmsgc,"out");


        }
}
