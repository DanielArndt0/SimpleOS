# SimpleOS

## V0.4.00 - Communication system update
### UART:
- Implemented byte read interrupt routine with 64 byte virtual input buffer.

### I2C:
- Implementation of the `send` and `receive` methods.

### Organization and Architecture:
- Some classes have been moved to the `Instance` `namespace`, which contains instances of system dependencies.

## V0.3.11 - Pinning system refactoring
### Hardware:
- Removed `GPIO` class.

## V0.3.10 - I2C Update
### I2C:
The `Core` library of `I2C` (`TWICore.h`) was developed.

### Organization and Architecture:
- Namespace `Time` has been added.

### Utils:
- The `IsPrimitive` operator checks whether the data type is primitive or not.

### Notes:
  - `TypeOf` operator has been enabled.

### Additions:
- **Core**:
  - `TWICore.h`
- **Utils**:
  - `IsPrimitive.h`
## V0.3.00 - Threads Update
### Thread and Interrupts
A library of `thread` executors was developed that work from the interrupts generated by `Watchdog` and `TIMER0`. Through the `Executors.h` library, it is possible to choose which executor the `thread` will be assigned to.

### RAM
A `RamInfo.h` library was developed that contains status information of each `RAM` subsection.
- `BssSection.h`: Get status information from `BSS` section.
- `DataSection.h`: Get status information from `Data` section.
- `HeapSection.h`: Get status information from `Heap` section.
- `StackSection.h`: Get status information from `Stack` section.

### Organization and Architecture:
- Namespace `Native` has been renamed for `Core`.
- Namespace `Error` has been added.
- Namespace `Handler` has been added.
- The `Ticks.h` class has been renamed to `Counter.h`
- The macros were divided into 4 files 
  - `HardwareMacros.h`
  - `SyntaxMacros.h`
  - `SystemMacros.h`
  - `UtilityMacros.h`

### Notes:
  - `TypeOf` operator has been disabled.

### Additions:
- **Concepts**:
  - `Identifiable.h`
  - `Printable.h` 

- **Core**: 
  - `TMR0Core.h`
  - `ResetCore.h`
  - `ResetType.h`

- **String**
  - `SimpleString.h`

- **Interrupts**
  - `Timer0.h`
  - **Executors**
    - `Executors.h`
    - `ThreadExecutor.h`
    - `TimerExecutor.h`
    - `WatchdogExecutor.h`
- **RAM**
  - `RamInfo.h`
  - **Sections**
    - `DataSection.h`
    - `BssSection.h`
    - `HeapSection.h`
    - `StackSection.h`
- **Threads**
  - `Thread.h`
- **SystemStatus**
  - `ErrorCode.h`
  - `Status.h`
- **Counter**
  - `Counter.h`

### Removals:
- **String**
  - `String.h`
- **Concepts**
  - `Default.h` (Default concept)
- **Managers**: 
  - `MemoryManager.h`
  - `TaskManager.h`
  - `ThreadManager.h`
- **Task**:
  - `Task.h`
  - `TaskAdapter.h`
  - `TaskController.h`
  - `TaskProperties.h`
  - `TaskLifecycle.h`
  - `TaskState.h`
- **RamAllocator**:
  - `Heap.h`
  - `RamAllocator.h`

## V0.2.00 - System Types Update

### Organization and Architecture:
- Namespace `Operators` has been renamed for `Utils`.

### System:
- The standard heap memory size of the system has been increased to 384 addresses (768 bytes).

### Types added:
 - `List<T>`
 - `ArrayList<T>`

### Types:
- Decrement, increment and bitwise operators have been implemented in the `Number<T>` class
- The `LinkedList<T>` and `ArrayList<T>` classes implement `List <T>`.

### Typedefs changes:
- `C_string` has been changed to `CString`.
- `Hashcode` alias removed.
- Alias of primitive types were changed to class `Number <T>`.

| Alias  | Type  |
|:---|:---|
| `Char` | `Number<char>`  |
| `UChar` | `Number<unsigned char>`  |
| `Int` | `Number<int>`  |
| `UInt` | `Number<unsigned int>`  |
| `Long` | `Number<long>`  |
| `ULong` | `Number<unsigned long>`  |
| `Float` | `Number<float>`  |
| `Double` | `Number<double>`  |
| `Bool` | `Number<bool>`  |

### Others:
- The `Operator << (Const String & Data)` is temporarily removed from the `UART` class for optimization.
- `UART` now prints boolean types.

### Notes:
- A bug was identified in the `malloc` method of the `RamAllocator` class. It will be fixed in the next updates.

## V0.1.02 - Code Refactoring
- System macro removed: `conceptualize`
- The `System` class now inherits from the `GPIO` class.

## V0.1.01 - Code Refactoring and Project Reorganization
- `Methods` class creation.
- The `System` class now inherits from the Watchdogtimer class.
- The `System` class now inherits from the Methods class.
- `Person.h` test class was removed.
- Addition of comments on the code.
- SimpleOS folder name change to System.

## V0.1.00 - Watchdog Timer Update
- Creation of the `WatchdogTimer` class. `WDTCore` optimization and refactoring of the `Ticks` class.
- Creation of `Macro INT(vector)` to handle interrupts
- Implementation of the `Bootable` and `Executable` concepts in the `System` class

### Removed classes:
- `MemoryHelper`
- `Interrupts.h`
- `VirtualRAM.h`

### Concepts created:
- `Bootable`
- `Executable`

