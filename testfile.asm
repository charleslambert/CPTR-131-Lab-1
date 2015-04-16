; C. Dodgson MLT1.ASM Multiply the value in memory location 3C (hex) by the value in
; location 47 using repeated addition, and store the result in D6. Note that this
; program may or may not be completely correct in its logic.
; Initialize

LDD R0, 3C R0 = upper limit for the loop; use to end the loop
LDI R1, 01 R1 = 1; use to increment the counter
LDI R2, 00 R2 = loop counter initialized to zero
LDD R3, 47 R3 = the second number to multiply; the number to add each time through the loop
LDI R4, 00 R4 = running total; initialize to zero
; Multiply by repeated addition

ADI R4, R4, R3 Add to running total
ADI R2, R2, R1 Add 1 to the loop counter; increment the loop counter
JMP R2, 12 Jump to 12 if R2 == R0; we’re done
JMP R0, 0A Otherwise jump to 0A (always, since R0 == R0)
STO R4, D6 Store the product into D6
HLT End of program
