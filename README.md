## 📖 About 

Cat is a general-purpose programming language, designed for humanity and cats.

![image](https://media.npr.org/assets/img/2021/08/11/gettyimages-1279899488_wide-f3860ceb0ef19643c335cb34df3fa1de166e2761-s1100-c50.jpg)


## 🚀 Getting Started

The langauge offers various instructions:

| Instruction  | Description |
| ------------- | ------------- |
| MEOW | Increment current memory block value by 1  |
| meow  | Decrement current memory block value by 1  |
| Meow  | Moves current memory position back one block  |
| meoW  | Moves current memory position forward one block  |
| MeoW  | Print value of current memory block  |
| mEow  | If no current value in the copy register, copy current memory block value. If there is a value in the copy register, and current memory block doesn't have value, then paste that value into the current memory block and clear the copy register |
| MeOw  | Start of condition |
| mEoW  | End of condition |
| MEow  | Start of loop |
| meOW  | End of loop |

### Conditions
When the MeOw instruction is executed, the program checks if current memory location value is greater than copy register value. if its greater, execute the instructions between MeOw and mEoW instructions.

### Loops
When the MEow instruction is executed, the program iterates over a sequence of instructions between MEow and meOW instructions, and the value stored in the timesToExecute register is decremented until it reaches the value zero.

## Showcase

Prints "Hello World!" to the screen:

```
MEOWMEOWMEOWMEOWMEOWMEOWMEOWMEOWMEOWMEOWMEOWMEOWMEOWMEOWMEOWMEOWMEOWMEOWMEOWMEOWMEOWMEOWMEOWMEOW
MeoWmEowmeoWmEowMEOWMEOWMEOWMEOWMEOWMEOWMEOWMEOWMEOWMEOWMEOWMEOWMEOWMEOWMEOWMEOWMEOWMEOWMEOWMEOW
MEOWMEOWMEOWMEOWMEOWMEOWMEOWMEOWMEOWMeoWmEowmeoWmEowMEOWMEOWMEOWMEOWMEOWMEOWMEOWMeoWMeoWMEOWMEOW
MEOWMeoWMeowMeowmEowMeowmEowmeowmeowmeowmeowmeowmeowmeowmeowmeowmeowmeowmeowmeowmeowmeowmeowmeow
meowmeowmeowmeowmeowmeowmeowmeowmeowmeowmeowmeowmeowmeowmeowmeowmeowmeowmeowmeowmeowmeowmeowMeoW
meoWmEowMeowMeowmEowMEOWMEOWMEOWMEOWMEOWMEOWMEOWMEOWMEOWMEOWMEOWMEOWMEOWMEOWMEOWMeoWmeoWmeoWmeoW
meoWMeoWmEowmeoWmEowMEOWMEOWMEOWMeoWmEowmeoWmEowmeowmeowmeowmeowmeowmeowMeoWmeowmeowmeowmeowmeow
meowmeowmeowMeoWMeowMeowMeowMeowMeowmEowMeowMeowmEowMEOWMeoW
```

Finds the largest element in the given array:
```
MEOWMEOWMEOWMEOWmEowmeoWmEowmeowmEowmeoWmEowMEOWMEOWMEOWmEowMeowMeowMEowMeOwmEowmEoWmeoWmeOWmeoW
meoWmEowMeoW
```
