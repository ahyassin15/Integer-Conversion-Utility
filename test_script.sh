#!/bin/bash
#
# A simple framework for regression testing the convert (ctest) script
#
# Returns the number of failed test cases.
#
# Format of a test:
#     test 'command' 'input file name' 'expected output file name' 'expected std error file name'
#
# Some example test cases are given. You should add more test cases.
#
# CAUTION: Uses temporary files named test_err.txt and test_out.txt
# 
# Sam Scott, McMaster University, 2024
#
declare -i tc=0
declare -i fails=0

############################################
# Run a single test. Runs a given command 
# to check the return value, stdout, and stderr
#
# GLOBALS: tc, fails
# PARAMS: $1 = command
#         $2 = input file name
#         $3 = expected std output file name
#         $4 = expected std error file name
#
# Assumes return value should be 0 if the
# std error file is empty. Otherwise it 
# should be 1.
#
# OUTPUTS: An pass/fail report showing the
# difference between expected and actual
# output on a failure (diff command)
############################################
test() {
    tc=tc+1

    local COMMAND=$1
    local INP=$2
    local EX_OUT=$3
    local EX_ERR=$4 

    EX_RET=1
    if [[ $(cat $EX_ERR) = "" ]]; then
        EX_RET=0
    fi
    $COMMAND < $INP > test_out.txt 2> test_err.txt
    RET=$?
    if [[ $RET != $EX_RET ]]; then
        echo "TC $tc Failed"
        echo "Returned $RET"
        echo "-----------"
        fails=$fails+1
        return
    fi
    DIFF=$(diff test_out.txt $EX_OUT)
    if [[ $DIFF != '' ]]; then
        echo "TC $tc Failed Standard Output"
        echo "$DIFF"
        echo "-----------"
        fails=$fails+1
        return
    fi
    DIFF=$(diff test_err.txt $EX_ERR)
    if [[ $DIFF != '' ]]; then
        echo "TC $tc Failed Standard Error"
        echo "$DIFF"
        echo "-----------"
        fails=$fails+1
        return
    fi

    echo "TC $tc Passed"
}


#Default base
test './ctest' 'inp1.txt' 'ex_out1.txt' 'empty.txt' 0

#Base 2 conversion
test './ctest -b 2' 'inp2.txt' 'ex_out2.txt' 'empty.txt' 0

#Invalid usage
test './ctest -a' 'empty.txt' 'empty.txt' 'usage.txt' 1

#Test help flag
test './ctest --help' 'empty.txt' 'empty.txt' 'help.txt' 1

#Test range and base flag
test './ctest -b 2 -r -3 3' 'empty.txt' 'outputs/ex_out3.txt' 'empty.txt' 0

#No base provided after -b flag
test './ctest -b' 'empty.txt' 'empty.txt' 'usage.txt' 1

#Invalid base
test './ctest -b 55' 'empty.txt' 'empty.txt' 'usage.txt' 1

#No range provided after -r flag
test './ctest -r' 'empty.txt' 'empty.txt' 'usage.txt' 1

#Invalid incomplete range
test './ctest -r 9' 'empty.txt' 'empty.txt' 'usage.txt' 1

#Invalid decreasing range
test './ctest -r 7 2' 'empty.txt' 'empty.txt' 'usage.txt' 1

#Non-long-int input
test './ctest' 'inp2.txt' 'ex_out4.txt' 'invalid_inp.txt' 1


# clean up
rm test_err.txt test_out.txt

# return code
exit $fails