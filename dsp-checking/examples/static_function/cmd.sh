export CBMC_CMD=/home/aske1807/cbmc/buildtest/dsp-checking/src

$CBMC_CMD/goto-cc/goto-cc -c static1.c -I.
$CBMC_CMD/goto-cc/goto-cc -c static2.c -I.
$CBMC_CMD/goto-cc/goto-cc static1.o static2.o -o exe
$CBMC_CMD/cbmc/cbmc exe
