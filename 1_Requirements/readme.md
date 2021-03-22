### Introduction

Message queues implement an asynchronous communication pattern between two or more processes/threads whereby the sending and receiving party do not need to interact with the message queue at the same time. Messages placed onto the queue are stored until the recipient retrieves them.

Message queues model, known as asynchronous messaging, prevents data loss and enables systems to continue to function if processes or connections fail. This allows developers to keep processes and applications separate, keeping their communications self-contained and event-driven to make the architecture more reliable.

In computer science, message queues and mailboxes are software-engineering components typically used for inter-process communication (IPC).

### Defining our system

*In our system the communication happens between Sensor,Controller and Display modules.

*Sensor will be continuously sending the data to Display

*Controller ask for data needed by the display and acknowledges it

*the communication happens with message queue as a medium with broadcast mechanism

*The system has a Qt GUI designed that displays the Sensor and Controller Data as received .

*Here The Sensor and Controller acts as Sender and Display acts as the Receiver.


## High Level Requirements 

| **Test ID** | **Description** | **Status** |
|-------------|-----------------|------------|
|HLR_01        |       Communication between Sensor and Display where Sensor sends random binary data and it is displayed on the Display | Implemented|
|HLR_02        | Communication between Controller and Display where Controller asks for the data from the user and acknowledges| Implemented |
|HLR_03      | Using message queue as a medium to transfer the data between the modules.| Implemented |


## Low Level Requirements 

| **Test ID** | **Description** | **Status** |
|-------------|-----------------|------------|
|HLR_01        |       Here 16-bit protocol is used that has Start frame,ID, data(8-bit) acknowledge bit and EOF | Implemented|
|HLR_02        | Sensor writes the random binary 16-bit data on the message queue(Sender) and it gets displayed on the Qt GUI | Implemented |
|HLR_03      | Further the sensor data is classified as Class A, B or C indicating low, medium and high dataFurther the sensor data is classified as Class A, B or C indicating low, medium and high data| Implemented |
|HLR_04        |      Controller asks for user to enter 8-bit data and further tells whtehr it is acknowledged or not based on the input | Implemented|
|HLR_05        | Sensor sends data unidirectionally to Display | Implemented |
|HLR_06      | Communication between Controller and Display is bi-directional | Implemented |






