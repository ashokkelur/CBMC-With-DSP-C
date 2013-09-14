#!/bin/bash
export CBMC_FOLDER=/home/aske1807/cbmc/buildtest/dsp-checking/src

for file in ./*.c 
do
    $CBMC_FOLDER/cbmc/cbmc $file

    OUT=$?
    if [ $OUT -ne 0 ]; then
        echo "Error["$OUT"]: while processing " $file
        break
    fi
done

#../cbmc fixed_type.c
#../cbmc simple_fun_call.c
#../cbmc struct_test.c
