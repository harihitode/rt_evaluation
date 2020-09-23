#! /bin/bash
echo "before"
taskset -p -a $(pgrep -f rt_evaluation)

ps -e -o pid= | xargs -n 1 taskset -p 0xFFFFFFFE
taskset -pca 0 $(pgrep -f rt_evaluation)

echo "after"
taskset -pa $(pgrep -f rt_evaluation)
