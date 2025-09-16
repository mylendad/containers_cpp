#!/bin/bash

CONFIG_FILE="$HOME/.docker/config.json"

if [ ! -f "$CONFIG_FILE" ]; then
    echo "Configuration file $CONFIG_FILE not found."
    exit 1
fi

# sudo apt-get install jq (for Debian/Ubuntu)
# brew install jq (for macOS)
    
if command -v jq &> /dev/null; then
    jq '. | .credsStore = ""' "$CONFIG_FILE" > tmp.$$.json && mv tmp.$$.json "$CONFIG_FILE"
    echo "SUCCESS"
else
    echo "FAIL"
    exit 1
fi
