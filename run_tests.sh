#!/usr/bin/bash

for file in $(ls tests/$2); do
    if [ ${file: -3} == ".sl" ]; then    
        id=$(echo tests/$2/${file} | cut -d "." -f 1 | tail -c 3)
        output=$(./$1 < tests/$2/${file} | diff tests/$2/result${id} -)
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
