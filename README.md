# SimpleOS

# V0.1.01 - Code Refactoring and Project Reorganization
- Methods class creation.
- The System class now inherits from the Watchdogtimer class.
- The System class now inherits from the Methods class.
- Person.h test class was removed.
- Addition of comments on the code.
- SimpleOS folder name change to System.


# V0.1.00 - Watchdog Timer Update
- Creation of the WatchdogTimer class. WDTCore optimization and refactoring of the Ticks class.
- Creation of Macro INT(vector) to handle interrupts
- Implementation of the Bootable and Executable concepts in the System class

### Removed classes:
- MemoryHelper
- Interrupts.h
- VirtualRAM.h

### Concepts created:
- Bootable
- Executable

