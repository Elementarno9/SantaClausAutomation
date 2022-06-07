# Santa Claus Automation

This is a test project. Santa requests our help in programming the whole gift wrapping and sending pipeline.

## Installation

Program was successfully build with Linux & C++17. Just run CMake.

## Running

There are three programs: `santa`, `elf` and `tests`. Their interfaces:

```./santa [-w <IP>] [-p <PORT>] [file1.xml] [file2.xml] ...```

```./elf [-w <IP>] [-p <PORT>]```

```./tests```

where `<IP>` and `<PORT>` need to be equal for elfs (senders) and santas (receivers).
