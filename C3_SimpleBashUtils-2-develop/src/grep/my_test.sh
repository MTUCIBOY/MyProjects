#!/bin/bash

SUCCESS=0
FAIL=0
COUNTER=0
DIFF_RES=""

declare -a tests=(
"VAR s testfolder/test_1"
"VAR int testfolder/test_2"
"VAR -e s -e int testfolder/test_3"
"VAR int testfolder/test_3"
"VAR -e int -f testfolder/pattern testfolder/test_3"
"VAR -e include testfolder/test_4"
"VAR -e include testfolder/test_5"
"VAR fd testfolder/empty"
)

testing()
{
    t=$(echo $@ | sed "s/VAR/$var/")
    ./s21_grep $t > test_s21_grep.log
    grep $t > test_sys_grep.log
    DIFF_RES="$(diff -s test_s21_grep.log test_sys_grep.log)"
    (( COUNTER++ ))
    if [ "$DIFF_RES" == "Files test_s21_grep.log and test_sys_grep.log are identical" ]
    then
      (( SUCCESS++ ))
      echo "\033[31m$FAIL\033[0m/\033[32m$SUCCESS\033[0m/$COUNTER \033[32mSUCCESS\033[0m grep $t"
    else
      (( FAIL++ ))
      echo "\033[31m$FAIL\033[0m/\033[32m$SUCCESS\033[0m/$COUNTER \033[31mFAIL\033[0m grep $t"
    fi
    rm test_s21_grep.log test_sys_grep.log
}


# 1 параметр
for var1 in v c l n h i s
do
    for i in "${tests[@]}"
    do
        var="-$var1"
        testing $i
    done
done

# 2 параметра
for var1 in v c l n h i s
do
    for var2 in v c l n h i s
    do
        if [ $var1 != $var2 ]
        then
            for i in "${tests[@]}"
            do
                var="-$var1 -$var2"
                testing $i
            done
        fi
    done
done

# 3 параметра
for var1 in v c l n h i s
do
    for var2 in v c l n h i s
    do
        for var3 in v c l n h i s
        do
            if [ $var1 != $var2 ]
            then
                if [ $var2 != $var3 ]
                then
                    for i in "${tests[@]}"
                    do
                        var="-$var1 -$var2 -$var3"
                        testing $i
                    done
                fi
            fi
        done
    done
done

echo "\033[31mFAIL: $FAIL\033[0m"
echo "\033[32mSUCCESS: $SUCCESS\033[0m"
echo "ALL: $COUNTER"
