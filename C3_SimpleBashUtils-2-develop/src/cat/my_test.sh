SUCCESS=0
FAIL=0
COUNTER=0
DIFF_RES=""

declare -a tests=(
    "VAR testfolder/test_case_cat.txt"
    "VAR testfolder/test_1_cat.txt"
    "VAR testfolder/test_2_cat.txt"
    "VAR testfolder/test_3_cat.txt"
    "VAR testfolder/test_4_cat.txt"
    "VAR testfolder/test_5_cat.txt"
    "VAR testfolder/empty"
)

declare -a extra=(
"-n testfolder/test_1_cat.txt testfolder/test_2_cat.txt"
"testfolder/test_5_cat.txt"
)

testing()
{
    t=$(echo $@ | sed "s/VAR/$var/")
    ./s21_cat $t > test_s21_cat.log
    cat $t > test_sys_cat.log
    DIFF_RES="$(diff -s test_s21_cat.log test_sys_cat.log)"
    (( COUNTER++ ))
    if [ "$DIFF_RES" == "Files test_s21_cat.log and test_sys_cat.log are identical" ]
    then
      (( SUCCESS++ ))
        echo -e "\033[31m$FAIL\033[0m/\033[32m$SUCCESS\033[0m/$COUNTER \033[32msuccess\033[0m cat $t"
    else
      (( FAIL++ ))
        echo -e "\033[31m$FAIL\033[0m/\033[32m$SUCCESS\033[0m/$COUNTER \033[31mfail\033[0m cat $t"
    fi
    rm test_s21_cat.log test_sys_cat.log
}

for var1 in b e n s t v
do
    for i in "${tests[@]}"
    do
        var="-$var1"
        testing $i
    done
done

# специфические тесты
for i in "${extra[@]}"
do
    var="-"
    testing $i
done

echo -e "\033[31mFAIL: $FAIL \033[0m"
echo -e "\033[32mSUCCESS: $SUCCESS\033[0m"
echo -e "ALL: $COUNTER"