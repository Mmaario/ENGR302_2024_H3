# Multiple Gain Remote Switched Transimpedance Amplifier Software Documentation

## **Note, None of the Commands are Case Sensitive.**

## Connecting to the on-board Microcontroller

The beaglebone will assign itself a static IP address of 192.168.7.2. It is listening for a TCP connection on port 88. To connect to the Beaglebone enter the command:

				nc 192.168.7.2 88
				
## Switching gain levels on the device

There are 6 gain levels built into the device. They are numbered 1 through 6 in ascending order. The levels are as shown below:

 - 1 = 1000
 - 2 = 500000
 - 3 = 1000000
 - 4 = 500000000
 - 5 = 1000000000
 - 6 = 10000000000
	
To select a gain level eneter the command:

				Gain <desired_gain_level>

Where **desired_gain_level** is gain level selected by the user.

## Checking current gain level

To check which of the gain levels is currently active on the device enter the command:

    Status

This command will return the current gain setting of the device. 

## Help while connected to the device

For help with the use of these commands as well as the map of gain values enter the command:

    Help
