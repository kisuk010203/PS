#!/bin/bash

for file in [0-9]*; do
    if [[ ! $file =~ \.c$|\.cpp$|\.py$|\.java$|\.rs$ ]]; then
        rm -f "$file"
    fi
done