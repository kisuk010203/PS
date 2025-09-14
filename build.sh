#!/bin/bash

result=$(find . -type f -name "$1.*" 2>/dev/null)

if [ -n "$result" ]; then
    echo "File Found at: $result"
    if [[ "$result" == *.cpp ]]; then
        g++ "$result" -o "src/a.out" -g
    elif [[ "$result" == *.c ]]; then
        gcc "$result" -o "src/a.out"
    elif [[ "$result" == *.py ]]; then
        python "$result"
    else
        echo "Not a c or cpp file"
    fi
else
    echo "File not found"
fi
