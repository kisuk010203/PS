#!/bin/bash

result=$(find . -type f -name "$1.*" 2>/dev/null)

if [ -n "$result" ]; then
    echo "File Found at: $result"
    if [[ "$result" == *.cpp ]]; then
        filename=$(basename "$result" .cpp)
        g++ "$result" -o "$filename" && "./$filename"
    elif [[ "$result" == *.c ]]; then
        filename=$(basename "$result" .c)
        gcc "$result" -o "$filename" && "./$filename"
    elif [[ "$result" == *.py ]]; then
        python "$result"
    else
        echo "Not a c or cpp file"
    fi
else
    echo "File not found"
fi
