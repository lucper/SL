#!/usr/bin/bash

TESTS=tests/test_tree/basic
PROGRAM=test_tree.out

for file in $(ls $TESTS); do
    if [ ${file: -3} == ".sl" ]; then    
        id=$(echo $TESTS/${file} | cut -d "." -f 1 | tail -c 3)
        output=$(./$PROGRAM < $TESTS/${file} | diff $TESTS/result${id} -)
        if [ $? != 0 ]; then
            echo "===== Test failed ====="
            echo "Input: ${file}"
            echo "${output}"
            echo "======================="
            echo ""
        else
            echo "${file} OK!"
            echo ""
        fi
    fi
done
