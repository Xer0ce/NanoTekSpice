
# NanoTekSpice

NanoTekSpice is a digital circuit simulator developed as a project for Epitech. It allows users to simulate various digital logic circuits and offers a command-line interface for specifying circuit configurations and input values.
## Installation

Installing the project is straightforward:

```bash
  > git clone git@github.com:Xer0ce/NanoTekSpice.git
  > cd NanoTekSpice
```

Executing it is just as simple:
```bash
  > make
  > ./nanotekspice -h
    Usage: ./nanotekspice [config_file].nts
```

## Usage

Here, an exemple of usage of NanoTekSpice

```bash
> cat -e or_gate.nts
    .chipsets:$
    input a$
    input b$
    4071 or$
    output s$
    .links:$
    a:1 or:1$
    b:1 or:2$
    or:3 s:1$


> ./nanotekspice or_gate.nts
    > b=0
    > a=1
    > simulate
    > display
    tick: 1
    input(s):
    a: 1
    b: 0
    output(s):
    s: 1
    > exit


> echo $?
    0
```

## Component usable

• Special components :

    • input
    • output
    • true
    • false
    • clock

• Elementary components:

    • and : single AND gate.
    • or : single OR gate.
    • xor : single XOR gate.
    • not : single INVERTER gate.

• Gates components :

    • 4001 : Four NOR gates.
    • 4011 : Four NAND gates.
    • 4030 : Four XOR gates.
    • 4069 : Six INVERTER gates.
    • 4071 : Four OR gates.
    • 4081 : Four AND gates.


## Notation

| Module | Language     | Grade                |
| :-------- | :------- | :------------------------- |
| `B-400-OOP` | `C++` | `Coming soon` |

#### Attention to Epitech students not to copy the code, otherwise you will receive a -84.