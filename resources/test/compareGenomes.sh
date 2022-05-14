#!/bin/bash

mkdir -p results

start_time=`date +%s`

../../build/main    "MERS-CoV.txt"              "../reference/Wuhan reference genome - NC_045512.2.txt"             >   "results/mersCov-vs-wuhan.txt"              ;   head -8 "results/mersCov-vs-wuhan.txt"              ;       printf "\n"     
../../build/main    "../reference/Wuhan reference genome - NC_045512.2.txt"     "SARS-CoV-2003.txt"                 >   "results/sarsCov2003-vs-wuhan.txt"          ;   head -8 "results/sarsCov2003-vs-wuhan.txt"          ;       printf "\n"     
../../build/main    "../reference/Wuhan reference genome - NC_045512.2.txt"     "Mystery genome 1 - OV806939.txt"   >   "results/genome1-vs-wuhan.txt"              ;   head -8 "results/genome1-vs-wuhan.txt"              ;       printf "\n"     
../../build/main    "../reference/Alpha B.1.1.7 - MZ314997.txt"                 "Mystery genome 1 - OV806939.txt"   >   "results/genome1-vs-alpha.txt"              ;   head -8 "results/genome1-vs-alpha.txt"              ;       printf "\n"     
../../build/main    "../reference/Beta B.1.351 - MZ314996.txt"                  "Mystery genome 1 - OV806939.txt"   >   "results/genome1-vs-beta.txt"               ;   head -8 "results/genome1-vs-beta.txt"               ;       printf "\n"     
../../build/main    "../reference/Delta B.1.617.2 - OM202516.txt"               "Mystery genome 1 - OV806939.txt"   >   "results/genome1-vs-delta.txt"              ;   head -8 "results/genome1-vs-delta.txt"              ;       printf "\n"     
../../build/main    "../reference/Gamma P.1 - MW642250.txt"                     "Mystery genome 1 - OV806939.txt"   >   "results/genome1-vs-gama.txt"               ;   head -8 "results/genome1-vs-gama.txt"               ;       printf "\n"     
../../build/main    "../reference/Omicron B.1.1.529 BA.1 - OM432158.txt"        "Mystery genome 1 - OV806939.txt"   >   "results/genome1-vs-omicronBA1.txt"         ;   head -8 "results/genome1-vs-omicronBA1.txt"         ;       printf "\n"     
../../build/main    "../reference/Omicron B.1.1.529 BA.2 - OM617939.txt"        "Mystery genome 1 - OV806939.txt"   >   "results/genome1-vs-omicronBA2.txt"         ;   head -8 "results/genome1-vs-omicronBA2.txt"         ;       printf "\n"     
../../build/main    "../reference/Wuhan reference genome - NC_045512.2.txt"     "Mystery genome 2 - MT345875.txt"   >   "results/genome2-vs-wuhan.txt"              ;   head -8 "results/genome2-vs-wuhan.txt"              ;       printf "\n"
../../build/main    "../reference/Alpha B.1.1.7 - MZ314997.txt"                 "Mystery genome 2 - MT345875.txt"   >   "results/genome2-vs-alpha.txt"              ;   head -8 "results/genome2-vs-alpha.txt"              ;       printf "\n"     
../../build/main    "../reference/Beta B.1.351 - MZ314996.txt"                  "Mystery genome 2 - MT345875.txt"   >   "results/genome2-vs-beta.txt"               ;   head -8 "results/genome2-vs-beta.txt"               ;       printf "\n"     
../../build/main    "../reference/Delta B.1.617.2 - OM202516.txt"               "Mystery genome 2 - MT345875.txt"   >   "results/genome2-vs-delta.txt"              ;   head -8 "results/genome2-vs-delta.txt"              ;       printf "\n"     
../../build/main    "../reference/Gamma P.1 - MW642250.txt"                     "Mystery genome 2 - MT345875.txt"   >   "results/genome2-vs-gama.txt"               ;   head -8 "results/genome2-vs-gama.txt"               ;       printf "\n"     
../../build/main    "../reference/Omicron B.1.1.529 BA.1 - OM432158.txt"        "Mystery genome 2 - MT345875.txt"   >   "results/genome2-vs-omicronBA1.txt"         ;   head -8 "results/genome2-vs-omicronBA1.txt"         ;       printf "\n"     
../../build/main    "../reference/Omicron B.1.1.529 BA.2 - OM617939.txt"        "Mystery genome 2 - MT345875.txt"   >   "results/genome2-vs-omicronBA2.txt"         ;   head -8 "results/genome2-vs-omicronBA2.txt"         ;       printf "\n"     
../../build/main    "../reference/Wuhan reference genome - NC_045512.2.txt"     "Mystery genome 3 - OU772970.txt"   >   "results/genome3-vs-wuhan.txt"              ;   head -8 "results/genome3-vs-wuhan.txt"              ;       printf "\n"
../../build/main    "../reference/Alpha B.1.1.7 - MZ314997.txt"                 "Mystery genome 3 - OU772970.txt"   >   "results/genome3-vs-alpha.txt"              ;   head -8 "results/genome3-vs-alpha.txt"              ;       printf "\n"     
../../build/main    "../reference/Beta B.1.351 - MZ314996.txt"                  "Mystery genome 3 - OU772970.txt"   >   "results/genome3-vs-beta.txt"               ;   head -8 "results/genome3-vs-beta.txt"               ;       printf "\n"     
../../build/main    "../reference/Delta B.1.617.2 - OM202516.txt"               "Mystery genome 3 - OU772970.txt"   >   "results/genome3-vs-delta.txt"              ;   head -8 "results/genome3-vs-delta.txt"              ;       printf "\n"     
../../build/main    "../reference/Gamma P.1 - MW642250.txt"                     "Mystery genome 3 - OU772970.txt"   >   "results/genome3-vs-gama.txt"               ;   head -8 "results/genome3-vs-gama.txt"               ;       printf "\n"     
../../build/main    "../reference/Omicron B.1.1.529 BA.1 - OM432158.txt"        "Mystery genome 3 - OU772970.txt"   >   "results/genome3-vs-omicronBA1.txt"         ;   head -8 "results/genome3-vs-omicronBA1.txt"         ;       printf "\n"     
../../build/main    "../reference/Omicron B.1.1.529 BA.2 - OM617939.txt"        "Mystery genome 3 - OU772970.txt"   >   "results/genome3-vs-omicronBA2.txt"         ;   head -8 "results/genome3-vs-omicronBA2.txt"         ;       printf "\n"     

printf "\n"
printf "\n"
echo Total execution time: $(expr `date +%s` - $start_time) s