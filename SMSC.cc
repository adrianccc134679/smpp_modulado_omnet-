//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#include "SMSC.h"

Define_Module(SMSC);

void SMSC::initialize()
{
    // TODO - Generated method body
}

void SMSC::handleMessage(cMessage *msg)
{
    cGate *arrivalGate = msg ->getArrivalGate();

    if (arrivalGate == gate("in1"))
    {
        std::string mes = msg->getFullName();
        char revString[mes.Size()];
        int max =mes.Size()-1;
        for (int i=0;i<mes.Size();i++)
           {
               revString[max++]=mes.at(i);
            }


        cMessage *tmsg = new cMessage("submit_sm_RESP");
        cMessage *tmsg1 = new cMessage("SRIF-SM");
        send (tmsg,"out1");
        send (tmsg1,"out2");
    }

    if (arrivalGate == gate("in2"))
        {
        cMessage *tmsg2 = new cMessage("FSM");
        send (tmsg2,"out3");
        }

    if (arrivalGate == gate("in3"))
                   {
                   cMessage *tmsg2 = new cMessage("Deliver_SM");
                   send (tmsg2,"out1");
                   }


}
