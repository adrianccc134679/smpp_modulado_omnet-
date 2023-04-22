

#include "ESME.h"

Define_Module(ESME);

void ESME::initialize()
{
    if ( strcmp(getName(),"ESME") == 0){
            cMessage *msg = new cMessage("submit_sm");
            send(msg,"out");
    }

}

void ESME::handleMessage(cMessage *msg)
{
  //  send(msg,"out");
}
