#! /bin/bash
echo "before"
ps -C rt_evaluation -o comm,pid,ppid,cls,rtprio,nice,%cpu

echo "execute"
sudo chrt -f -p 99 $(pgrep -f rt_evaluation)

echo "after"
ps -C rt_evaluation -o comm,pid,ppid,cls,rtprio,nice,%cpu

