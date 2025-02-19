#!/bin/bash

# Get today's date in DD-MM-YYYY format
today=$(date +"%d-%m-%Y")

# Set the directory path
log_dir="$(dirname "$0")/daily-logs"
log_file="$log_dir/$today.md"

# Check if file exists
if [ -f "$log_file" ]; then
    echo "Log file for $today already exists!"
else
    # Create the file with template
    cat > "$log_file" << EOL
# $today

## Things to do today

## Technical Workspace

I did not discuss anything today.

EOL
    echo "Created new log file: $today.md with template"
fi