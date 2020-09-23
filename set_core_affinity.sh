#! /bin/bash
echo "before"
taskset -p -a $(pgrep -f rt_evaluation)

echo "execute"
taskset -pca 0 $(pgrep -f rt_evaluation)

echo "after"
taskset -pa $(pgrep -f rt_evaluation)
