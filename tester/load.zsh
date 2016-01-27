#!/usr/bin/zsh

nprocessors=`lscpu | grep -oP "(?<=Core\(s\) per socket:\s{4})\d+"`
nsockets=`lscpu | grep -oP "(?<=Socket\(s\):\s{13})\d+"`
ncores=$(($nprocessors * $nsockets))
result_dir=./result/`date +%s`
targets=({0..6})
if [[ $# -ge 1 ]]; then;
  result_dir=./result/$1
  if [[ $# -ge 2 ]]; then;
    targets=(${@:2})
  fi;
fi;

mkdir -p $result_dir/load/{cache,ahs,tsx}
for i in $targets; do;
  for ((j = 1; j <= 10000; j *= 10)); do;
#    perf stat -e cache-misses,cache-references,L1-dcache-loads,L1-dcache-load-misses \
#      ./concurrency-test $i 1000000 $ncores $j 0.5 1000 8 8 0.2 >> $result_dir/load/cache/$i 2>&1
    amplxe-cl -r=$result_dir/load.cellar/ahs/$i/$j -c advanced-hotspots ./concurrency-test $i 1000000 $ncores $j 0.5 1000 8 8 0.2 \
      >> $result_dir/load/ahs/$i
    if [[ 0 -le $i && $i -le 3 ]]; then;
      amplxe-cl -r=$result_dir/load.cellar/tsx/$i/$j -c tsx-exploration ./concurrency-test $i 1000000 $ncores $j 0.5 1000 8 8 0.2 \
        >> $result_dir/load/tsx/$i
    fi;
  done;
done;
