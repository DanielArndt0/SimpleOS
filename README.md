# SimpleOS

## V0.2.00 - System Types Update

#### Organization and Architecture:
- Namespace `Operators` has been renamed for` Utils`.

#### System:
- The standard heap memory size of the system has been increased to 384 addresses (768 bytes).

#### Types added:
 - `List<T>`
 - `ArrayList<T>`

#### Types:
- Decrement, increment and bitwise operators have been implemented in the `Number<T>` class
- The `LinkedList<t>` and `ArrayList <t>` classes implement `List <t>`.

#### Typedefs changes:
- `C_string` has been changed to` CString`.
- `Hashcode` alias removed.
- Alias of primitive types were changed to class `Number <t>`.

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

#### Others:
- The `Operator << (Const String & Data)` is temporarily removed from the `UART` class for optimization.
- `UART` now prints boolean types.

#### Notes:
- A bug was identified in the `malloc` method of the` RamAllocator` class. It will be fixed in the next updates.

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

#### Removed classes:
- `MemoryHelper`
- `Interrupts.h`
- `VirtualRAM.h`

#### Concepts created:
- `Bootable`
- `Executable`

