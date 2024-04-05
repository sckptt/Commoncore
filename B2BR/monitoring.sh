#!/bin/bash

# Architecture shows here:
echo -n "#Architecture: "; uname -a

# Number of physical processors shows here:
echo -n "#CPU physical :"; grep "physical id" /proc/cpuinfo | wc -l

# Number of virtual processors shows here:
echo -n "#vCPU : "; grep processor /proc/cpuinfo | wc -l

# RAM usage info shows here:
echo -n "#Memory Usage: "; free -m | awk '$1 == "Mem:" {printf "%s/%sMb (%.2f%%)\n", $3, $2, $3/$2*100}'

# Disk memory usage info shows here:
echo -n "#Disk Usage: "; df -m | grep "/dev/" | gerp -v "/boot" | awk '{memory_used += $3} {memory_total += $2} END {printf "%s/%.0fGb (%.d%%)\n", memory_used, memory_total/1024, memory_used/memory_total*100}'

# CPU load shows here:
echo -n "#CPU load: "; vmstat | tall -1 | awk '{print $15}'

# Last reboot info shows here:
echo -n "#Last boot: "; who -b | awk '$1 == "system" {print $3 " " $4}'

# LVM use info shows here:
echo -n "#LVM use: "; lsblk | grep lvm | awk '{if ($1) {print "yes"; exit;} else {print "no"}}'

# The number of TCP connections shows here:
echo -n "#Connections TCP : "; ss -ta | grep ESTAB | wc -l

# The number of users using the server shows here:
echo -n "#User log: "; users | wc -l

# The IPv4 address of your server and its 
# MAC (Media Access Control) address shows here:
echo -n "#Network: "; ip link | grep "link/ether" | awk '{print $2}'

# The number of commands executed with 
# the sudo program shows here:
echo -n "#Sudo : "; journalctl _COMM=sudo | grep COMMAND | wc -l