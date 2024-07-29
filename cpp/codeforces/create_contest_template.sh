#!/bin/bash

BOILER_PLATE_FILE_PATH=/home/jitendra/Repository/dummy/java/DSA/cpp/BoilerPlate
CODE_FORCES_CONTEST_DIRECTORY_PATH=/home/jitendra/Repository/dummy/java/DSA/cpp/codeforces
CONTEST_NAME=$1
CONTEST_PROBLEM=$2
CONTEST_FOLDER=$CODE_FORCES_CONTEST_DIRECTORY_PATH/$CONTEST_NAME

number_to_excel_column() {
    local num=$1
    local column=""

    while [ $num -gt 0 ]; do
        local remainder=$(( (num - 1) % 26 ))
        column=$(printf "\x$(printf %x $((remainder + 65)))")$column
        num=$(( (num - 1) / 26 ))
    done

    echo $column
}

mkdir "$CONTEST_FOLDER"
# shellcheck disable=SC2004
for (( i = 1; i <= $CONTEST_PROBLEM; i++ )); do
    cat $BOILER_PLATE_FILE_PATH > "$CONTEST_FOLDER/Problem$(number_to_excel_column "$i").cpp"
done