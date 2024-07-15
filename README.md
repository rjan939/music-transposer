# Music-Transposer
This is just a simple program to help me learn how to transpose notes by semitones or by changing key signatures as well. 

## Prerequisites
- some sort of C compiler(GNU, Clang, etc.)
- make tool installed(or you could just alternatively compile it manually)

## Installation
1. Clone the repository:
`git clone https://github.com/rjan939/music-transposer.git`
## Usage
**To use the Music-Transposer, follow these steps:**

`make transposer`
`./transpose <semitones> <notes...>`
**each argument after the semitones should be a note**

**If you don't have make tool installed, follow these steps:**

1. `gcc transposer.c -o transpose`
2. `./transpose <semitones> <notes...>`

## Examples
- Transpose from a key of F Major to C Major
- This would be down 5 semitones
`make transposer` -> `./transpose -5 F G A Bb C D E F`
- This would output:
`Transposed Sequence: C D E F G A B C`



