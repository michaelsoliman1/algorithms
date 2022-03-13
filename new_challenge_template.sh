#!/bin/sh

DIR=""
CHALLENGE_NUM=0

if [ $# -eq 0 ]
then
        echo "Missing options!"
        echo "(run $0 -h for help)"
        echo ""
        exit 1
fi

while getopts "h" OPTION; do
        case $OPTION in
                h)
                      echo "Usage:"
                      echo "$0 <algorithm> <challenge number>"
                      echo ""
                      echo "available options: "
                      echo "1) brute_force 2) sorting 3) trees 4) db"
                      echo ""
                      exit 0
                      ;;
                *)
        esac
done

if  [ "$1" = "brute_force" ]; then
    DIR="1_brute_force"
elif [ "$1" = "sorting" ]; then
    DIR="2_sorting"
elif [ "$1" = "trees" ]; then
    DIR="3_trees"
elif [ "$1" = "db" ]; then
    DIR="4_dynamic_programming"
else
    echo "not supported"
fi

CHALLENGE_NUM=$2

while [ ${#CHALLENGE_NUM} -lt 2 ] ; do
    CHALLENGE_NUM="0${CHALLENGE_NUM}"
done

echo "
add_executable("$DIR"_ch$CHALLENGE_NUM $DIR/challenge_$CHALLENGE_NUM/main.cpp)

" >> CMakeLists.txt

mkdir "$DIR/challenge_$CHALLENGE_NUM"
cd "$DIR/challenge_$CHALLENGE_NUM" || exit

echo "
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

/// \IMPLEMENTATION -
/// \TESTCASES -
int main(){

}
" > main.cpp

echo "
# [<challenge_name>](<challenge_rrl>)

<description>

**Input Format**

-

**Constraints**

-

**Output Format**

-


**Sample Input 0**
```
```

**Sample Output 0**

```
```

**Explanation 0**

" > readme.md

