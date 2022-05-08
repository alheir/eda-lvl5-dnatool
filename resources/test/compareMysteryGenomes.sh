#!/bin/bash

mkdir -p comparisons

../../build/main "Mystery genome 1 - OV806939.txt" "../reference/Alpha B.1.1.7 - MZ314997.txt"           > "comparisons/genome1-vs-alpha.txt"
../../build/main "Mystery genome 1 - OV806939.txt" "../reference/Beta B.1.351 - MZ314996.txt"            > "comparisons/genome1-vs-beta.txt"
../../build/main "Mystery genome 1 - OV806939.txt" "../reference/Delta B.1.617.2 - OM202516.txt"         > "comparisons/genome1-vs-delta.txt"
../../build/main "Mystery genome 1 - OV806939.txt" "../reference/Gamma P.1 - MW642250.txt"               > "comparisons/genome1-vs-gama.txt"
../../build/main "Mystery genome 1 - OV806939.txt" "../reference/Omicron B.1.1.529 BA.1 - OM432158.txt"  > "comparisons/genome1-vs-omicronBA1.txt"
../../build/main "Mystery genome 1 - OV806939.txt" "../reference/Omicron B.1.1.529 BA.2 - OM617939.txt"  > "comparisons/genome1-vs-omicronBA2.txt"

../../build/main "Mystery genome 2 - MT345875.txt" "../reference/Alpha B.1.1.7 - MZ314997.txt"           > "comparisons/genome2-vs-alpha.txt"
../../build/main "Mystery genome 2 - MT345875.txt" "../reference/Beta B.1.351 - MZ314996.txt"            > "comparisons/genome2-vs-beta.txt"
../../build/main "Mystery genome 2 - MT345875.txt" "../reference/Delta B.1.617.2 - OM202516.txt"         > "comparisons/genome2-vs-delta.txt"
../../build/main "Mystery genome 2 - MT345875.txt" "../reference/Gamma P.1 - MW642250.txt"               > "comparisons/genome2-vs-gama.txt"
../../build/main "Mystery genome 2 - MT345875.txt" "../reference/Omicron B.1.1.529 BA.1 - OM432158.txt"  > "comparisons/genome2-vs-omicronBA1.txt"
../../build/main "Mystery genome 2 - MT345875.txt" "../reference/Omicron B.1.1.529 BA.2 - OM617939.txt"  > "comparisons/genome2-vs-omicronBA2.txt"

../../build/main "Mystery genome 3 - OU772970.txt" "../reference/Alpha B.1.1.7 - MZ314997.txt"           > "comparisons/genome3-vs-alpha.txt"
../../build/main "Mystery genome 3 - OU772970.txt" "../reference/Beta B.1.351 - MZ314996.txt"            > "comparisons/genome3-vs-beta.txt"
../../build/main "Mystery genome 3 - OU772970.txt" "../reference/Delta B.1.617.2 - OM202516.txt"         > "comparisons/genome3-vs-delta.txt"
../../build/main "Mystery genome 3 - OU772970.txt" "../reference/Gamma P.1 - MW642250.txt"               > "comparisons/genome3-vs-gama.txt"
../../build/main "Mystery genome 3 - OU772970.txt" "../reference/Omicron B.1.1.529 BA.1 - OM432158.txt"  > "comparisons/genome3-vs-omicronBA1.txt"
../../build/main "Mystery genome 3 - OU772970.txt" "../reference/Omicron B.1.1.529 BA.2 - OM617939.txt"  > "comparisons/genome3-vs-omicronBA2.txt"