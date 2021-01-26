#!/bin/bash

set –o pipefail;

cd $( dirname $0 )
BASE_DIR=$(pwd)
BUILD_PATH="$(pwd)/build"

#Run unit tests
$BASE_DIR/build/unittest --gtest_output="xml:${BUILD_PATH}/RockPaperScissorsUTResult.xml"
runStatus1=$?

PIDS=($runStatus1)

# after all processes finish, check their exit codes in STATUS[].
i=0
for st in ${PIDS[@]}; do
  if [ ${st} -eq 0 ] || [ ${st} -eq 1 ]; then
    echo "${i} Unit Tests are done. Exit code: ${st}"
  else
    echo "${i} Unit Tests failed. Exit code: ${st}" 
    exit ${st}
  fi
  ((i+=1))
done

exit 0
