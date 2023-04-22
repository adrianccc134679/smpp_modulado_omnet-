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

network SMPP
{
    @display("bgb=596,264");
    submodules:
        ESME: ESME {
            @display("p=39,156");
        }
        HLR: HLR {
            @display("p=465,47");
        }
        MC: MC {
            @display("p=312,202");
        }
        MOBILE: MOBILE {
            @display("p=551,202");
        }
        SMSC: SMSC {
            @display("p=176,47");
        }
    connections:
        ESME.out --> SMSC.in1;
        HLR.out --> SMSC.in2;
        MC.out1 --> SMSC.in3;
        SMSC.out1 --> ESME.in;
        SMSC.out2 --> HLR.in;
        SMSC.out3 --> MC.in1;
        MC.out2 --> MOBILE.in;
        MOBILE.out --> MC.in2;
}
