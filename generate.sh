touch ./test_files/"N$1_M$2.in"
RANGE=$(($(($2-6))/2))+1
for ((i = 0; i < $1; ++i))
do
  echo $(($(($((`od -vAn -N4 -tu4 < /dev/random` % RANGE))*2))+6))
done > ./test_files/"N$1_M$2.in"