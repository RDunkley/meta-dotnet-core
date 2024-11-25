#!/bin/bash

# Check if the directory is provided as an argument
if [ -z "$1" ]; then
    echo "Usage: $0 <path_to_search>"
    exit 1
fi

# Directory to search (provided as an argument)
SEARCH_DIR="$1"

# Temporary file to store all dependencies
TEMP_FILE=$(mktemp)

# Find all executables and .so files
find "$SEARCH_DIR" -type f -not -name "*.dll" | while read -r file; do
    if file "$file" | grep -qE 'ELF|executable'; then
        # List dependencies using ldd and append to TEMP_FILE
        # echo "Processing $file..."
        ldd "$file" 2>/dev/null | awk '{print $1}' | xargs -n1 basename >> "$TEMP_FILE"
    fi 
done

# Sort and deduplicate the dependencies
sort -u "$TEMP_FILE"

# Clean up temporary file
rm -f "$TEMP_FILE"

