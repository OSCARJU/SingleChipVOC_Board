# SingleChipVOC_Board
The PCB design was simulated using Proteus System Designer which is the software most suitable to create a high functionality PCB, after the simulation we can generate the layout in order to size the elements.
Input
In this group we can find the sensor input, the external trigger and the voltage supply (5 volts Arduino Nano and 24 Volts relays)
Figure 2.1 Inputs
The way to condition the sensor is using a voltage current transform, due to the sensor uses a current value, the resistor transforms the current to voltage it means the range 4 mA to 25 mA to 1 volts and 5 Volts, the resistors used are 150Ω and 100Ω. The external trigger works with resistors connected in series (1kΩ and 1kΩ). The final resistor is to control the current of the diode Led, the value of this resistor is from 100 Ω to 330Ω.

The rest of the information can be found in the handbook
