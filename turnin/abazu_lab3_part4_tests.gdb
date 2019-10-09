# Test file for Lab2_introToAVR


# commands.gdb provides the following functions for ease:
#   test "<message>"
#       Where <message> is the message to print. Must call this at the beginning of every test
#       Example: test "PINA: 0x00 => expect PORTC: 0x01"
#   checkResult
#       Verify if the test passed or failed. Prints "passed." or "failed." accordingly,
#       Must call this at the end of every test.
#   expectPORTx <val>
#       With x as the port (A,B,C,D)
#       The value the port is epected to have. If not it will print the erroneous actual value
#   setPINx <val>
#       With x as the port or pin (A,B,C,D)
#       The value to set the pin to (can be decimal or hexidecimal
#       Example: setPINA 0x01
#   printPORTx f OR printPINx f
#       With x as the port or pin (A,B,C,D)
#       With f as a format option which can be: [d] decimal, [x] hexadecmial (default), [t] binary
#       Example: printPORTC d
#   printDDRx
#       With x as the DDR (A,B,C,D)
#       Example: printDDRB

echo ======================================================\n
echo Running all tests..."\n\n

# Example test:
#test "PINA: 0x00 => PORTB: 0x0F"
# Set inputs
#setPINA 0x00
#setPINB 0x00
# Continue for several ticks
#continue 2
# Set expect values
#expectPORTC 0
# Check pass/fail
#checkResult

# Add tests below

test "PINA: 0x00 => PORTB: 0x00, PORTC: 0x00"
    setPINA 0x00
    continue 5
    expectPORTB 0x00
    expectPORTC 0x00
    checkResult

test "PINA: 0xBF => PORTB: 0x0B, PORTC: 0xF0"
    setPINA 0xBF
    continue 5
    expectPORTB 0x0B
    expectPORTC 0xF0
    checkResult

test "PINA: 0xFF => PORTB: 0x0F, PORTC: 0xF0"
    setPINA 0xFF
    continue 5
    expectPORTB 0x0F
    expectPORTC 0xF0
    checkResult

test "PINA: 0x31 => PORTB: 0x03, PORTC: 0x10"
    setPINA 0x31
    continue 5
    expectPORTB 0x03
    expectPORTC 0x10
    checkResult

test "PINA: 0xF6 => PORTB: 0x0F, PORTC: 0x60"
    setPINA 0xF6
    continue 5
    expectPORTB 0x0F
    expectPORTC 0x60
    checkResult

test "PINA: 0xF8 => PORTB: 0x0F, PORTC: 0x80"
    setPINA 0xF8
    continue 5
    expectPORTB 0x0F
    expectPORTC 0x80
    checkResult


# Report on how many tests passed/tests ran
set $passed=$tests-$failed
eval "shell echo Passed %d/%d tests.\n",$passed,$tests
echo ======================================================\n