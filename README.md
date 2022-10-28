# IFJprojekt
- In this project we are creating compiler

## State Machine

```
Keyword
S       -> [a-zA-Z]      | [a-zA-Z] KEYWORD 
KEYWORD -> [a-zA-Z0-9]   | [a-zA-Z0-9] KEYWORD
```
---
```
VarRead
S       -> $[a-zA-Z]     | $[a-zA-Z] VAR
VAR     -> [a-zA-Z0-9]   | [a-zA-Z0-9] VAR
```
---
```
String
S       -> "[^"]        | "[^"] STR
STR     -> [^"]         | [^"] 
```
---
```
Divide
S       ->  [ / ]    | [ / ] DIV

One line comment
DIV      ->  [ / ]   |  [ / ] CMT
CMT      ->  [ EOL ] |  [ EOL ] CMT

Coment start
DIV      ->  [ * ]  |   [ * ] CS
```
---
```
Multiply
S       ->  [ * ]    | [ * ] MUL

Coment end
MUL      ->  [ / ]    | [ / ] CE
```
---
```
Addition
S       ->  [ + ]   | [ + ] ADD
```
---
```
Substriction
S       ->  [ - ]    | [ - ] SUB
```
---
```
Lower
S       ->  [ < ]    | [ < ] LWR

Lower or equal
LWR     ->  [ = ]
```
---
```
Higher
S       ->  [ > ]    | [ > ] HGR

Higher or equal
HGR     ->  [ = ]
```

