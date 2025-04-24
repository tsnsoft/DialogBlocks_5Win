#!/bin/bash
cd "$(dirname "$0")"

echo "Adding all changes..."
git add .

datetime=$(date +%Y%m%d%H%M%S)
commit_msg="rev. $datetime"

echo "Commit_msg: $commit_msg"
git commit -m "$commit_msg"

echo "Skipping push (local save only)"
# git push origin master  # убери или закомментируй, если не хочешь пушить

echo "Done!"

