++++++++        Set Cell #0 to 8
[
    >++++       Add 4 to Cell #1; this will always set Cell #1 to 4
    [           as the cell will be cleared by the loop
        >++     Add 2 to Cell #2
        >+++    Add 3 to Cell #3
        >+++    Add 3 to Cell #4
        >+      Add 1 to Cell #5
        <<<<-   Decrement the loop counter in Cell #1
    ]           Loop till Cell #1 is zero; number of iterations is 4
    >+          Add 1 to Cell #2
    >+          Add 1 to Cell #3
    >-          Subtract 1 from Cell #4
    >>+         Add 1 to Cell #6
    [<]         Move back to the first zero cell you find; this will
                be Cell #1 which was cleared by the previous loop
    <-          Decrement the loop Counter in Cell #0
]               Loop till Cell #0 is zero; number of iterations is 8

The result of this is:
Cell #2 has value 65
Cell #3 has value 72
Cell #4 has value 100
Cell #5 has value 32
Cell #6 has value 8

>.                     Cell #2 is "H"
>---.                  Cell #3 is "e"
+++++++..+++.          "l" "l" "o"
>>.                    Cell #5 is space
<-.                    Cell #4 is "W"
<.                     Cell #3 is "o"
+++.------.--------.   "r" "l" "d"
>>+.                   Cell #6 is "!"